#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> A(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  vector<int> c(3, 0);
  ll ans = 1;
  ll MOD = 1e9 + 7;
  for(ll i = 0; i < N; i++){
    ll cnt = 0;
    ll k;
    REP(j, 3){
      if(A[i] == c[j]){
        cnt++;
        k = j;
      }
    }
    c[k]++;
    ans = ans * cnt % MOD;
  }
  cout << ans % MOD << endl;
}