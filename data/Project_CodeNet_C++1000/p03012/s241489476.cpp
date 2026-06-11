#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int N;
  cin >> N;

  int sum = 0;
  vector<int> W(N);
  rep(i, N) {
    cin >> W[i];
    sum += W[i];
  }

  int ans = 100000;
  int left = 0;
  int right = 0;
  rep(i, N -1) {
    left += W[i];
    right = sum - left;
    ans = min(ans, abs(left - right));
  }

  cout << ans << endl;

  return 0;
}
