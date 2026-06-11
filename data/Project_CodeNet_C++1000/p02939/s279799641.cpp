#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  string t, p;
  rep(i,s.size()) {
    t += s[i];
    if(t==p) continue;
    p = t;
    t = "";
    ans++;
  }
  cout << ans << endl;
  return 0;
}