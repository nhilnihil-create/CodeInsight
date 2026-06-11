#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  // mapを使えば頻度は簡単に出せる
  map<string, int> mp;
  rep(i,n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }
  ll ans = 0;
  for (auto &p : mp) {
    int s = p.second;
    ans += (ll)s*(s-1)/2;
  }
  cout << ans << endl;
  return 0;
}
