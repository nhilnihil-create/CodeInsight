#include <iostream>
#include <vector>
using namespace std;

int main() {

  long long int n;
  cin >> n;

  vector< long long int > v;

  for ( long long int i = 0; i < n; i++ ) {

    long long int in;
    cin >> in;

    v.push_back( in );

  }

  long long int cnt = 0;
  vector< long long int > g;
  g.push_back( 1 );
  long long int m = 0;
  while(1) {
    if ( g[g.size()-1] > n ) break;
    m++;
    g.push_back( g[ g.size() - 1 ] * 2 + 1 );
  }

  for ( long long int b = m - 1; b >= 0; b-- ) {

    for ( long long int i = g[b]; i < n; i++ ) {

      long long int k = v[i];

      long long int j = i - g[b];

      while( j >= 0 && v[j] > k ) {

	v[ j + g[b] ] = v[j];
	j = j - g[b];
	cnt++;

      }

      v[ j + g[b] ] = k;

    }

  }


  cout << m << endl;
  for ( long long int i = 0; i < m; i++ ) {
    if ( i != 0 ) cout << " ";
    cout << g[ m - i - 1 ];
  }
  cout << endl << cnt << endl;

  for ( long long int i = 0; i < n; i++ ) {

    cout << v[i] << endl;

  }

  return 0;

}