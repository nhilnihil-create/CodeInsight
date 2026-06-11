#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {

  long long int n;
  cin >> n;

  vector< long long int > x, y;

  for ( long long int i = 0; i < n; i++ ) {

    long long int in;
    cin >> in;
    x.push_back( in );

  }

  for ( long long int i = 0; i < n; i++ ) {

    long long int in;
    cin >> in;
    y.push_back( in );

  }

  long double d[4] = {};

  for ( long long int i = 0; i < n; i++ ) {

    long long int k = x[i] - y[i];
    if ( k < 0 ) k = -k;
    d[0] += k;
    d[1] += k * k;
    d[2] += k * k * k;
    d[3] = max( d[3], 1.00L * k );

  }

  cout << fixed << setprecision(10) << d[0] << endl << pow( d[1], 1.0 / 2 ) << endl << pow( d[2], 1.0 / 3 ) << endl << d[3] << endl;;

  return 0;

}