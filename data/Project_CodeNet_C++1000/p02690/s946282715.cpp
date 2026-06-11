#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
200^5-199^5
=7920399001
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll X; cin>>X;
  
  for(ll a=-200; a<=200; a++){
    for(ll b=-200; b<=200; b++){
      ll c = a*a*a*a*a - b*b*b*b*b;
      if (c == X){
        cout <<a<<" "<<b<<endl;
        return 0;
      }
    }
  }
}
