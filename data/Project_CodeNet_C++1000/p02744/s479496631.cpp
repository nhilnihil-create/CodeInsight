#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n;
void dfs(int x, string s) {
  if (x == n) {
    cout << s << endl;
    return;
  }

  if (x == 1 && s[0] > 'a')
    return;

  rep(i, 0, n) {
    char maxc = 'a';
    rep(j, 0, (int)s.size()) chmax(maxc, s[j]);
    if (x && (char)(maxc + 1) < (char)('a' + i))
      break;
    dfs(x + 1, s + string{(char)('a' + i)});
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  dfs(0, "");
}
