#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int n;

void dfs(string s, int a) {
  if (s.length() == n)
    cout << s << endl;
  else {
    for (char c = 'a'; c <= 'a' + a; ++c) {
      if (c != 'a' + a)
        dfs(s + c, a);
      else
        dfs(s + c, a + 1);
    }
  }
}

int main() {
  cin >> n;
  dfs("", 0);
  return 0;
}
