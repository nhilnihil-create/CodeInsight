#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l(n + 1, 0);
  rep(i, 1, n + 1) {
    cin >> l[i];
    l[i] += l[i - 1];
  }
  int ans = 0;
  rep(i, 0, n + 1) {
    if (l[i] > x) {
      ans = i;
      break;
    }
  }
  if (ans == 0) ans = n + 1;
  cout << ans << endl;
  return 0;
}