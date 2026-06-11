#include <cstdio>

int main( void )
{
    while ( true )
    {
        int h, w;
        scanf( "%d %d", &h, &w );
        if ( ( h == 0 ) && ( w == 0 ) ) break;

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
    return 0;
}