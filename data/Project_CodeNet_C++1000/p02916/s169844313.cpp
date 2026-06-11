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
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n - 1);
  int ans = 0;
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n - 1) cin >> c[i];
  int index = -3;
  rep(i, 0, n) {
    ans += b[a[i] - 1];
    if (index == a[i] - 1) ans += c[index - 1];
    index = a[i];
  }
  cout << ans << endl;
  return 0;
}