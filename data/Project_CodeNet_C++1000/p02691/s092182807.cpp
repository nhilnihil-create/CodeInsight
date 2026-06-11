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
  
  ll N; cin >> N;
  vector<ll> A(N, 0);
  rep(i, N) cin >> A[i];
  map<ll,ll> MP;
  ll ans = 0;
  rep(i, N){
    ans += MP[i-A[i]];
    MP[A[i]+i]++;
  }
  cout<<ans<<endl;
}
