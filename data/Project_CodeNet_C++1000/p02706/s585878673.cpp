#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
// #define MULTIPLE_TESTS 1

void solve() {
  int n, m;
  cin >> n >> m;
  int sum = 0, x;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    sum += x;
  }
  if (sum > n) {
    cout << -1 << endl;
  } else {
    cout << n - sum << endl;
  }
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  while (t--) {
    solve();
  }

  return 0;
}