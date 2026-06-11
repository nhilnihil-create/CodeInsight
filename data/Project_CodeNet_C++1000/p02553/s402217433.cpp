#include<bits/stdc++.h>
using namespace std ;

#define int long long 

signed main(){
  int a, b ,c ,d ;
  cin >> a >> b >> c >> d ;
  cout << max( {a*c , a*d , b*c , b*d} ) ;
}