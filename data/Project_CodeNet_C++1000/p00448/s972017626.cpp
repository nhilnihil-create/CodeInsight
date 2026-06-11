#include <iostream>
#include <cstdlib>
#include <cassert>
const static int R_MAX = 12;
const static int C_MAX = 10012;
using namespace std;

int bt( int s[ R_MAX ][ C_MAX ], int r, int c, int depth ) {
  if( depth == r ) {
    int sum = 0;
    for( int cj = 0; cj < c; cj++ ) {
      int cnt_1 = 0;
      int cnt_m1 = 0;
      for( int ri = 0; ri < r; ri++ ) {
        if( s[ ri ][ cj ] == 1 ) {
          cnt_1++;
        } else {
          cnt_m1++;
        }
      }
      sum += max( cnt_1, cnt_m1 );
    }
    return sum;
  }

  int na = bt( s, r, c, depth + 1 );
  for( int cj = 0; cj < c; cj++ ) {
    s[ depth ][ cj ] = -s[ depth ][ cj ];
  }
  int nb = bt( s, r, c, depth + 1 );
  for( int cj = 0; cj < c; cj++ ) {
    s[ depth ][ cj ] = -s[ depth ][ cj ];
  }

  return max( na, nb );
}

int main() {
  int r, c;
  int s[ R_MAX ][ C_MAX ] = {0}; // ura: -1, omote: 1, none: 0

  while( 1 ) {
    cin >> r >> c;
    if( !r && !c ) { break; }
    for( int ri = 0; ri < r; ri++ ) {
      for( int cj = 0; cj < c; cj++ ) {
        int tmp;
        cin >> tmp;
        s[ ri ][ cj ] = !tmp ? -1 : 1;
      }
    }

    cout << bt( s, r, c, 0 ) << endl;
  }

  return EXIT_SUCCESS;
}