#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  map<string,ll> m;
  ll ans = 0;
  rep(i,0,n) {
    string s;
    cin >> s;
    vector<string> t(10);
    rep(j,0,10) t[j] = s.substr(j,1);
    sort(t.begin(), t.end());
    s = "";
    rep(j,0,10) s += t[j];
    ans += m[s];
    m[s]++;
  }
  cout << ans << endl;
  return 0;
}
