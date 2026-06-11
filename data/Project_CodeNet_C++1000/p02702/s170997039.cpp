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
  
  string S; cin>>S;
  ll MOD = 2019;
  vector<ll> pre(200010, 0);
  pre[0] = 0;
  pre[1] = 1;
  map<ll,ll> M;
  M[0]++;
  ll ssz = S.size();
  for(ll i=2; i<=ssz; i++){
    pre[i] = pre[i-1] * 10;
    pre[i] %= MOD;
  }
  
  ll tmp = 0, ans = 0;
  for(ll i=ssz-1; i>=0; i--){
    tmp += (S[i]-'0') * pre[ssz-i];
    tmp %= MOD;
    ans += M[tmp];
    M[tmp]++;
  }
  cout<<ans<<endl;
}
