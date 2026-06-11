#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;

  vector<long int> L( N );

  int count = 0;

  for( int i = 0; i < N; i++ ) 
    cin >> L.at( i );

  sort( L.begin(), L.end() );

  for( int i = 0; i < N - 2; i++ ) {
    for( int j = 1; j < N - 1; j++ ) {
      for( int k = 2; k < N; k++ ) {
	if( L.at( i ) + L.at( j ) > L.at( k ) && L.at( j ) + L.at( k ) > L.at( i ) && L.at( k ) + L.at( i ) > L.at( j ) && L.at( i ) != L.at( j ) && L.at( j ) != L.at( k ) && L.at( k ) != L.at( i ) && i < j && j < k) {
	  count++;
     // cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	}
      }
    }
  }

  cout << count << endl;
}