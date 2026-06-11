#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

  while( true ) {
    int n;
    cin >> n;
    if( n == 0 ) {
      break;
    }

    double sum = 0;
    double d = 0;
    vector<double> dat( 0 );
    for( int i = 0; i < n; i++ ) {
      cin >> d;
      dat.push_back( d );
      sum += d;
    }

    double ave = sum / n;
    double buf = 0, stdev;
    for( int i = 0; i < n; i++ ) {
      buf += pow( dat[ i ] - ave, 2 );
    }
    stdev = sqrt( buf / n );
    cout << fixed << setprecision(8);
    cout << stdev << endl;
  }

  return 0;
}