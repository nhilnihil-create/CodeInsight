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
  int n;
  cin >> n;
  int s1 = 0, s2 = 0;
  vector<int> w(n);
  rep(i, 0, n) {
    cin >> w[i];
    s2 += w[i];
  }
  int ans = s2;
  rep(i, 0, n) {
    s2 -= w[i];
    s1 += w[i];
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans << endl;
  return 0;
}