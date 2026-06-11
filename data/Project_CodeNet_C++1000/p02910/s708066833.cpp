#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int lenS = sz(s);
  bool bl = true;
  rep(i, lenS) {
    if (i&1 && s[i] == 'R') bl = false;
    else if (i%2 == 0 && s[i] == 'L') bl = false;
  }
  if (bl) puts("Yes");
  else puts("No");
  return 0;
}