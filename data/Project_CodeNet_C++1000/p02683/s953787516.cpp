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
  
  ll N, M, X, oo=4e18; cin >> N >> M >> X;
  vector<vector<ll>> C(N, vector<ll>(M+1, 0));
  rep(i, N) rep(j, M+1)
    cin >> C[i][j];
  ll ans = oo;
  ll end = 1LL<<N;
  for(ll i=1; i<end; i++){
    vector<ll> A(M+1, 0);
    for(ll j=0; j<N; j++){
      if ((i & (1<<j))){
        for(ll k=0; k<=M; k++)
          A[k] += C[j][k];
      }
    }
    //check
    for (ll m=1; m<=M; m++){
      if (A[m] < X)
        break;
      if (m == M)
        chmin(ans, A[0]);
    }
  }
  if (ans == oo)
    ans = -1;
  cout << ans << endl;
}
