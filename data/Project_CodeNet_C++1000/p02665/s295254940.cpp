#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int N;
  cin >> N;

  int sum = 0;
  vector<int> A(N+1);
  for (int &a:A) {
    cin >> a;
    sum += a;
  }

  if (N == 0 && A[0] == 1) {
    cout << 1 << endl;
    return;
  }

  if (A[0]) {
    cout << -1 << endl;
    return;
  }

  int ans = 1;
  int oya = 1;
  for (int d = 1; d <= N; d++) {
    if (oya * 2 < A[d]) {
      cout << -1 << endl;
      return;
    }

    ans += A[d];
    ans += min(oya * 2 - A[d], sum-A[d]);
    oya = min(oya * 2 - A[d], sum-A[d]);
    sum -= A[d];
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
