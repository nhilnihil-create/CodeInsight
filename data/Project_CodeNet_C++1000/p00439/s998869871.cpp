#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int x,s;
int a[100000];

int main(void){

  while( cin >> n >> m , n || m ){

    for( int i = 0 ; i < n ; i++ ){
      cin >> a[i];
    }
    x = 0;
    for( int i = 0 ; i < m ; i++ ){
      x += a[i];
    }
    s = x;
    for( int i = 0 ; i < n - m ; i++ ){
      x -= a[i];
      x += a[i + m];
      if( s < x ) s = x;
    }

    cout << s << endl;

  }
  return 0;
}