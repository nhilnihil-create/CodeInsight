#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (char i = '0'; i <= '9'; ++i) {
    for (char j = '0'; j <= '9'; ++j) {
      for (char k = '0'; k <= '9'; ++k) {
        int a = 0;
        rep(l, n) {
          if (a == 0 && s[l] == i) ++a;
          else if (a == 1 && s[l] == j) ++a;
          else if (a == 2 && s[l] == k) ++a;
        }
        if (a == 3) ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}