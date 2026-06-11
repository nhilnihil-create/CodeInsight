#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef pair<int, int> P;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<int> x(N), y(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  int ans = N;
  rep(i, N) {
    rep(j, N) {
      if(i == j) continue;
      long long p = x[i] - x[j];
      long long q = y[i] - y[j];

      int cnt = 0;

      rep(k, N) {
        rep(l, N) {
          if(k == l) continue;
          long long xdiff = x[k] - x[l];
          long long ydiff = y[k] - y[l];
          if(p == xdiff && q == ydiff) cnt++;
        }
      }
      ans = min(ans, N-cnt);
    }
  }
  cout << ans << endl;

  return 0;
}
