#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1LL << 60;


int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  ll M; cin >> M;
  vector<ll> D(M), C(M);
  for(int i = 0; i < M; ++i) cin >> D[i] >> C[i];

  ll ans = 0, cnt = 0;
  for(int i = 0; i < M; ++i) {
    ans += C[i];
    cnt += D[i] * C[i];
  }
  cout << ans-1 + (cnt-1) / 9;

  return 0;
}
