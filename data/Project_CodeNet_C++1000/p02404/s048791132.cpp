#include <cstdio>

void printFrame( int h, int w );

int main( void )
{
    while ( true )
    {
        int h, w;
        scanf( "%d %d", &h, &w );
        if ( ( h == 0 ) && ( w == 0 ) ) break;
        printFrame( h, w );
    }
    return 0;
}

void printFrame( int h, int w )
{
    for ( int j = 0; j < w; j++ )   {   printf("#");    }
    printf("\n");
    
    for ( int i = 1; i < ( h - 1 ); i++ )
    {
        printf("#");
        for ( int j = 1; j < ( w - 1 ); j++ )   {   printf(".");    }
        printf("#\n");
    }

    for ( int j = 0; j < w; j++ )   {   printf("#");    }
    printf("\n");

    printf("\n");
}