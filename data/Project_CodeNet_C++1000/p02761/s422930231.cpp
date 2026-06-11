#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  int n, m;
  cin >> n >> m;
  string  ans;
  rep(i,n) ans.push_back('0');
  vector<bool> t(n, false);
  rep(i,m) {
    int s;
    char c;
    cin >> s >> c;
    s--;
    if (t[s] && ans[s] != c) {
      cout << -1 << endl;
      return 0;
    }
    ans[s] = c;
    t[s] = true;
  }
  if (ans == "0") {
    cout << ans << endl;
    return 0;
  }
  if (t[0] && ans[0] == '0') {
    cout << -1 << endl;
    return 0;
  }
  if (ans[0] == '0') ans[0] = '1';
  cout << ans << endl;
  return 0;
}