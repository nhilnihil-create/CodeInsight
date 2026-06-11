#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, D;
  cin >> N >> D;

  vector<int> X( N ), Y( N );
  int count = 0;
  
  for( int i = 0; i < N; i++ ) {
    cin >> X.at( i ) >> Y.at( i );
    if( sqrt( ( double )( pow( X.at( i ), 2 ) + pow( Y.at( i ), 2 ) ) ) <= D )
      count++;
  }

  cout << count << endl;
}