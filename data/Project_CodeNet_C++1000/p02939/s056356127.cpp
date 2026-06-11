#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  set<string> v;

  string x = "";
  string prev = "";
  int ans = 0;
  rep(i,s.size()) {
    x.push_back(s[i]);
    if (x == prev) continue;
    prev = x;
    x = "";
    ans++;
  }

  cout << ans << endl;
  return 0;
}
