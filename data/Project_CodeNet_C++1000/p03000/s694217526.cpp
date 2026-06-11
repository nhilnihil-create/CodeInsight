#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  rep(i, N) {
    cin >> L[i];
  }

  int ans = 1;
  int pos = 0;
  rep(i, N) {
    pos += L[i];
    if (pos <= X) {
      ans++;
    } else {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
