#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; string s;
  cin >> n >> s;
  int ans = 0;
  rep(i,0,n-2) {
    if (s.substr(i,3) == "ABC") {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
