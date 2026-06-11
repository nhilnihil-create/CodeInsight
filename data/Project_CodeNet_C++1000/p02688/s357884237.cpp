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
  
  ll N,K; cin>>N>>K;
  vector<int> A(101,0);
  rep(i, K){
    ll d; cin>>d;
    rep(j, d){
      ll a; cin>>a;
      A[a]++;
    }
  }
  ll ans = 0;
  for(int i=1; i<=N; i++)
    if(A[i] == 0) ans++;
  cout<<ans<<endl;
}
