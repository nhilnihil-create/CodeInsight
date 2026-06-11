#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  int dist = abs(A - B);
  if (V <= W) {
    cout << "NO" << endl;
    return 0;
  }
  int s = V - W;
  if (dist <= (ll)s * T) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
