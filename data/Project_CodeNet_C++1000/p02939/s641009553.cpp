#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s;
  cin >> s;

  string prev = "";
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    string c(1, s[i]);
    if (prev == c) {
      if (i + 1 < s.size()) {
        i++;
        prev = "";
      } else {
        break;
      }
    } else {
      prev = c;
    }
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
