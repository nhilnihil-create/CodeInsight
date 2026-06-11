#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, M, K; cin >> N >> M >> K;
  vector<ll> A(N+1, 0), B(M+1, 0);
  rep(i, N) cin >> A[i+1];
  rep(i, M) cin >> B[i+1];
  rep(i, N) A[i+1] += A[i];
  rep(i, M) B[i+1] += B[i];
  ll ans = 0;
  rep(i, N+1){
    ll k = K-A[i];
    if (k < 0)
      break;
    ll tmp = i;
    auto itr = lower_bound(all(B), k+1);
    ll add = itr - B.begin() - 1;
    tmp += add;
    chmax(ans, tmp);
  }
  cout << ans << endl;
}
