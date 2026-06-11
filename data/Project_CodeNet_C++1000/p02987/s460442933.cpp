#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, s.size()) {
    rep(j, s.size()) {
      if(i == j) continue;
      if(s.at(i) == s.at(j)) cnt++;
    }
  }
  if(cnt == 4) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}