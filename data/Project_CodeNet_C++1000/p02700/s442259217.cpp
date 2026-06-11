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
  int th, ts, ah, as;
  cin >> th >> ts >> ah >> as;
  int t_turn = 1;
  while (th > 0 && ah > 0) {
    if (t_turn) {
      ah -= ts;
    } else {
      th -= as;
    }
    t_turn = t_turn ^ 1;
  }
  if (th <= 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
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