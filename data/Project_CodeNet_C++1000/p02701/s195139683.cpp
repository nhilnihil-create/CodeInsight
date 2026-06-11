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
  int n;
  cin >> n;
  set<string> s;
  string item;
  for (int i = 0; i < n; ++i) {
    cin >> item;
    s.insert(item);
  }
  cout << s.size() << endl;
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