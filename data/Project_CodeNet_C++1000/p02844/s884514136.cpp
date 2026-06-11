#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1000) {
    vector<int> num(3);
    int tmp = i;
    for (int j = 2; j >= 0; j--) {
      num[j] = tmp%10;
      tmp /= 10;
    }
    int idx = 0;
    rep(j, n) {
      if (num[idx] == s[j]-'0')
        idx++;
      if (idx == 3) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}