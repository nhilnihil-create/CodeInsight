#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string S;
  cin >> S;
  int max = 0;
  int count = 0;

  for( int i = 0; i < 3; i++ ) {
    if( S.at( i ) == 'R' ) {
      count++;
    }
    else {
      if( max < count ) {
	max = count;
      }
      count = 0;
    }
  }
  
  if( max < count )
    max = count;

  cout << max << endl;
}
      