#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;

  bool can = false;

  for( int i = 1; i <= 9; i++ )
    for( int j = 1; j <= 9; j++ )
      if( i * j == N )
	can = true;

  if( can )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}