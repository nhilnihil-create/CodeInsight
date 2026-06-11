#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int _w;

int n , m , f[N][N][2][2] , flag;
long long ans;
char str[N];

int main( void ) {
  _w = scanf("%s%d",str+1,&m);
  n = strlen( str + 1 );
  if( str[1] != str[n] || m == 1 ) {
    for( int i = 1 , r ; i <= n ; i = r + 1 ) {
      r = i;
      while( r < n && str[r + 1] == str[i] ) ++r;
      ans += ( r - i + 1 ) / 2;
    }
    cout << ans * m;
    return 0;
  }
  flag = 1;
  for( int i = 2 ; i <= n ; ++i ) if( str[i] != str[i - 1] ) flag = 0;
  if( flag ) return printf("%lld",1LL*n*m/2),0;
  for( int i = 1 , r ; i <= n ; i = r + 1 ) {
    r = i;
    while( r < n && str[r + 1] == str[i] ) ++r;
    if( i != 1 && r != n ) ans += 1LL * ( ( r - i + 1 ) / 2 ) * m;
  }
  int l = 1 , r = n;
  while( str[l + 1] == str[1] ) ++l;
  while( str[r - 1] == str[n] ) --r;
  ans += 1LL * ( m - 1 ) * ( ( l + ( n - r + 1 ) ) / 2 );
  ans += l / 2 + ( n - r + 1 ) / 2;
  cout << ans;
  return 0;
}
