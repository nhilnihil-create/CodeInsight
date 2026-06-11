#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  string ans = "";
  rep(i,s.size()) {
    char t = s.at(i);
    for(int j = 0; j < n; j++) {
      if (char(t) == 'Z') {
        t = 'A';
        continue;
      }
      t = char(t+1);
    }
    ans += t;
  }
  cout << ans << endl;
}
