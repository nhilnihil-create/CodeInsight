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

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N; cin>>N;
  N %= 10;
  if (N == 3)
    cout<<"bon"<<endl;
  else if(N==0 || N==1 || N==6 || N==8)
    cout<<"pon"<<endl;
  else
    cout<<"hon"<<endl;
}
