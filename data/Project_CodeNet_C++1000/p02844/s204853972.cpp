#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N;
  string s;
  cin >> N >> s;
  int ans = 0;
  rep(i, 0, 1000) {
    string t = to_string(1000 + i).substr(1);
    int start = 0;
    int cnt = 0;
    for (char c : t) {
      rep(i, start, N) {
        if (s[i] == c) {
          start = i + 1;
          cnt++;
          break;
        }
      }
    }
    if(cnt==3)ans++;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}