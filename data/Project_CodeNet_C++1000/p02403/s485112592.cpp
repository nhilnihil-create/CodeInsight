#include<stdio.h>
 
void drawRectangle( int H, int W)
{
    int i,j;
     
    for( i=0; i<H; i++) {
        for( j=0; j<W; j++) {
            printf( "#");
        }
        printf( "\n");
    }
    printf( "\n");
    return;
}
 
int main( void ) 
{
    int H,W;
 
    for( ; ; ) {
        scanf( "%d%d", &H, &W ); 
        if( 0==H && 0==W ) { break; }
 
        drawRectangle( H, W );
    }
 
    return 0;
}