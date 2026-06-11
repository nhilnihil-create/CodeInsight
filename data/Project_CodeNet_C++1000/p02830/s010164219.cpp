#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  string ans = "";
  rep(i,0,n) {
    ans += s.substr(i,1) + t.substr(i,1);
  }
  cout << ans << endl;
  return 0;
}
