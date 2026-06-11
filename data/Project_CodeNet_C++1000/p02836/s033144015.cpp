#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  rep(i,0,n/2) {
    if (s[i] != s[n-i-1]) ans++;
  }
  cout << ans << endl;
  return 0;
}
