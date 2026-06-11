#include<bits/stdc++.h>
using namespace std ;

int main()
{
  int x, n ;
  cin >> x >> n ;
  vector<int> p(n) ;

  for (int i = 0; i < n; i++) {
    int d ;
    cin >> d ;
    p.at(i) = d - x ;
  }

  vector<int> a(200) ;
  a.at(0) = 0 ;
  for (int i = 1; i < 100 ; i++) {
    a.at(2 * i -1 ) = (-1) * i ;
    a.at(2 * i ) = i ;
  }

  for (int i = 0; i < n ; i++) {
    if ( p.at(i) == 0 ) {
      a.at(0) = 101 ;
    }else if ( p.at(i) < 0 ) {
      a.at( (-2)* p.at(i) - 1 ) = 101 ;
    }else {
      a.at( p.at(i) * 2 ) = 101 ;
    }
  }

  for (int i = 0; i < 200 ; i++) {
    if ( a.at(i) != 101 ) {
      cout << a.at(i) + x << endl ;
      break ;
    }
  }
  return 0 ;
}
