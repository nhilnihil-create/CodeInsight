/*input
5
24 11 8 3 16
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int M = 1e6+5;
int p[M];

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  rep(i, n) {
    bool ok = true;
    if (p[a[i]] == 0) {
      ans++;
      p[a[i]] = -1;
      for (int j = a[i]*2; j < M; j += a[i]) {
        p[j] = 1;
      }
    }
    else if (p[a[i]] == -1) {
      ans--;
      p[a[i]] = 1;
    }
  }
  cout << ans << endl;
}