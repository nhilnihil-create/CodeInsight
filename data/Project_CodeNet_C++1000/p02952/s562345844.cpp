#include<bits/stdc++.h>
using namespace std;

int checkOorE( int i );

int main( void )
{
  int N;
  cin >> N;

  int countO = 0;

  for( int i = 1; i <= N; i++ ) {
    countO += checkOorE( i );
  }
  cout << countO << endl;
}

int checkOorE( int i )
{
  int count = 0;
  
  while( i ) {
    i /= 10;
    count++;
  }
  if( count % 2 == 0 )
    return 0;
  else
    return 1;
}