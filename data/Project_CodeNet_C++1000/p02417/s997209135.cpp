#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
  string buf;

  int cnt[ 26 ] = { 0 };
  int idx = 0;

  while( cin >> buf ) {
    for( int i = 0; i < buf.size(); i++ ) {
      char ch = buf[ i ];

      if( isupper( ch ) ) {
        idx = ch - 65;
        cnt[ idx ] += 1;
      }

      if( islower( ch ) ) {
        idx = ch - 97;
        cnt[ idx ] += 1;
      }
    }
  }

  for( int i = 0; i < 26; i++ ) {
    cout << (char)( i + 97 ) << " : " << cnt[ i ] << endl;
  }
  return 0;
}