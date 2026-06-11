#include <iostream>
void printRectangle( int h, int w );

int main( void )
{
    while ( true )
    {
        int h, w;
        std::cin >> h >> w;
        if ( ( h == 0 ) && ( w == 0 ) ) break;
        printRectangle( h, w );
    }
    return 0;
}

void printRectangle( int h, int w )
{
    for ( int i = 0; i < h; i++ )
    {
        for ( int j = 0; j < w; j++ )
        {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}