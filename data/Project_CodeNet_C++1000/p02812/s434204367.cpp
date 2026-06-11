
  #include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;

  vector<char> S( N );
  int count = 0;

  for( int i = 0; i < N; i++ ) {
    cin >> S.at( i );

  }

  for( int i = 0; i < N - 2; i++ ){
    if( S.at( i ) == 'A' && S.at( i + 1 ) == 'B' && S.at( i + 2 ) == 'C' ) {
      count++;
    }
  }

  cout << count << endl;
}