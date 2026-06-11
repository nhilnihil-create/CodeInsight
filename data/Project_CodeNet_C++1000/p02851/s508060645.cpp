#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#define rep(i,n) for(int i=0;i<(n);++i)
int main() {
  int N, K; cin >> N >> K;

  ll A[N], sum[N+1];
  sum[0] = 0;
  rep(i, N) {
    cin >> A[i];
    --A[i];
    sum[i+1] = sum[i] + A[i];
    sum[i+1] %= K;
  }
  ll ans = 0;
  map<ll, int> m;
  rep(i, min(N+1, K)) {
    ++m[sum[i]];
  }
  rep(l, N) {
    --m[sum[l]];
    ans += m[sum[l]];
    if (l+K < N+1)
      ++m[sum[l+K]];
  }
  cout << ans << endl;

  return 0;
}
