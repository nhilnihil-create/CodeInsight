#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;



int main(){
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  FOR(i, K, N+2){
    ll max = N * i - (ll)i*(i-1)/2;
    ll min = (ll)i*(i-1) / 2;
    ans += max - min + 1;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}