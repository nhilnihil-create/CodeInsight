#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

bool dfs(string& s, int cur, int obj) {
  if(cur >= s.size()) return false;
  if(s[cur] == '#') return false;
  if(cur == obj) return true;

  return dfs(s, cur + 1, obj) || dfs(s, cur + 2, obj);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  --a; --b; --c; --d;
  string s; cin >> s;

  if(c > d) {
    // b->c 間で3つ空白がなければaはbを追い越せない
    int maxw = 0;
    int wcnt = 0;
    for(int i = b - 1; i <= d + 1; ++i) {
      if(s[i] == '.') {
        ++wcnt;
        chmax(maxw, wcnt);
      } else {
        wcnt = 0;
      }
    }
    if(maxw < 3) {
      cout << "No" << endl;
      return 0;
    }
  }

  bool ans1 = dfs(s, b, d);
  bool ans2 = dfs(s, a, c);
  if(ans1 && ans2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
