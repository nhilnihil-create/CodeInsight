#include <bits/stdc++.h>
using namespace std ;
#define ll long long

inline int D(){
    int t ;
    scanf( "%d" , &t ) ;
    return t ;
}
inline ll LLD(){
    ll t ;
    scanf( "%lld" , &t ) ;
    return t ;
}
//const int INF = 0x3f3f3f3f;
//const int mod=1e9+7;
//const double pi=3.14159265359;
//###################################################################

int main() {
  string s,t;
  cin>>s>>t;
  int cnt=0;
  for(int i=0;s[i];i++){
      if(s[i]!=t[i])cnt++;
  }
  cout<<cnt;
}