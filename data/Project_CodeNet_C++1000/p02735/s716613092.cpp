#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int _w;

int f[N][N] , n , m;
char str[N][N];
bool g[N][N];

int main( void ) {
  _w = scanf("%d%d",&n,&m);
  for( int i = 1 ; i <= n ; ++i ) _w = scanf("%s",str[i] + 1);
  memset( f , 0x3f , sizeof f );
  if( str[1][1] == '.' ) f[1][1] = 0;
  else {
    g[1][1] = 1;
    for( int i = 1 ; i <= n ; ++i )
      for( int j = 1 ; j <= m ; ++j ) 
        if( g[i][j] ) {
          if( i < n && str[i + 1][j] == '#' ) g[i + 1][j] = 1;
          if( j < m && str[i][j + 1] == '#' ) g[i][j + 1] = 1;
        }
    for( int i = 1 ; i <= n ; ++i )
      for( int j = 1 ; j <= m ; ++j )
        if( g[i][j] )
          f[i][j] = 1;
  }
  for( int i = 1 ; i <= n ; ++i )
    for( int j = 1 ; j <= m ; ++j )
      if( f[i][j] < 0x3f3f3f3f ) {
        if( i < n && str[i + 1][j] == '.' )
          f[i + 1][j] = min( f[i + 1][j] , f[i][j] );
        if( j < m && str[i][j + 1] == '.' )
          f[i][j + 1] = min( f[i][j + 1] , f[i][j] );
        for( int x = i ; x <= n ; ++x )
          for( int y = j ; y <= m ; ++y )
            g[x][y] = 0;
        if( i < n && str[i + 1][j] == '#' ) g[i + 1][j] = 1;
        if( j < m && str[i][j + 1] == '#' ) g[i][j + 1] = 1;
        for( int x = i ; x <= n ; ++x )
          for( int y = j ; y <= m ; ++y )
            if( g[x][y] ) {
              if( x < n && str[x + 1][y] == '#' ) g[x + 1][y] = 1;
              if( y < m && str[x][y + 1] == '#' ) g[x][y + 1] = 1;
              f[x][y] = min( f[x][y] , f[i][j] + 1 );
            }
      }
  printf("%d",f[n][m]);
  return 0;
}
