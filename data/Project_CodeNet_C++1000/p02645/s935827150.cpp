#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s, ans;

int main() {
  cin >> s;
  rep (i, 3) ans += s[i];
  cout << ans << endl;
  return 0;
}
