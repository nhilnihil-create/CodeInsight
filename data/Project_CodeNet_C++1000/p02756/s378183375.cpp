#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;

  // trueの時，文字列は順方向
  bool state = true;
  // a:先頭に付加する文字列，b:末尾に付加する文字列
  string a,b;

  rep(i,q){
    int t;
    cin >> t;
    if (t == 1) {
      state = !state;
      continue;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f==1) {
        // 先頭に文字を追加
        if (state) a.push_back(c);
        else b.push_back(c);
      } else {
        // 末尾に文字を追加
        if (state) b.push_back(c);
        else a.push_back(c);
      }
    }
  }

  reverse(a.begin(),a.end());
  string ans = a + s + b;
  if (!state) reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
