#include <stdio.h>
 
int
main (
  int   argc,
  char *argv[ ]
  )
{
  int i, j;
 
  for ( ; ; )
  {
    int h, w;
 
    scanf ( "%d%d", &h, &w );
    if ( h == 0 && w == 0 ) break ;
 
    for ( i = 0; i < h; ++i )
    {
      for ( j = 0; j < w; ++j )
      {
        if ( i == 0 || i == h - 1
          || j == 0 || j == w - 1 )
        {
          putchar ( '#' );
        }
        else
        {
          putchar ( '.' );
        }
      }
      puts ( "" );
    }
    puts ( "" );
  }
 
  return ( 0 );
}