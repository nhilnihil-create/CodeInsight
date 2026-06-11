#include <iostream>

using namespace std;

int main()
{
  int n;
  int *a;
  long int total_a = 0;
  long int e = 1;
  long int ans = 0;
  
  cin >> n;
  a = (int*)malloc(( n + 1 ) * sizeof( int ));
  if ( NULL == a ) { return -1; }
  for ( int i = 0 ; i <= n ; ++i ) { cin >> a[i]; total_a += a[i]; }
  
  for ( int i = 0 ; i <= n ; ++ i ) {
    ans += e;
    if ( e < a[i] ) { cout << -1 << endl; return 0; }
    e = 2 * ( e - a[i] );
    total_a -= a[i];
    e = min( e, total_a );
  }
  
  cout << ans << endl;
}