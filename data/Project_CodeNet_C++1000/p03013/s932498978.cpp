#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  rep(i,M) cin >> a[i];
  for (int i = 1; i < M; ++i) {
    if (a[i] - a[i-1] == 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  vector<ll> ways(N+1);
  ways[0] = 1; ways[1] = 1, ways[2] = 2;
  for (int i = 3; i <= N; ++i) {
    ways[i] = (ways[i-1] + ways[i-2]) % 1000000007;
  }

  if (M == 0) {
    cout << ways[N] << endl;
    return 0;
  }

  vector<int> p(M+1);
  p[0] = a[0] - 1;
  p[M] = N - a[M-1] - 1;
  for (int i = 1; i < M; ++i) {
    p[i] = a[i] - a[i-1] - 2;
  }

  ll ans = 1;
  rep(i,M+1) {
    ans *= ways[p[i]];
    ans %= 1000000007;
  }
  cout << ans << endl;

  return 0;
}