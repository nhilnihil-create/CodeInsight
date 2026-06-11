#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  bool flag = true;
  rep(i,s.size()) {
    if (i%2==0 && s[i]=='L' || i%2!=0 && s[i]=='R') {
      flag = false;
      break;
    }
  }
  if (flag) puts("Yes");
  else puts("No");
  return 0;
}