#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  int x = 100 * A / 8.0;
  rep(i, 0, 13) {
    int res8 = (x + i) * 0.08;
    int res10 = (x + i) * 0.1;
    // cout << i << " " << x + i << " " << res8 << endl;
    if (res8 == A && res10 == B) {
      cout << x + i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
