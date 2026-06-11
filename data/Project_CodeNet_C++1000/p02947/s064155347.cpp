#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<string> v;
  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    v.push_back(s);
  }
  unordered_map<string, int> mp;
  ll ans = 0;
  rep(i, n) {
    mp[v[i]]++;
    if (mp[v[i]] >= 2) ans += mp[v[i]] - 1;
  }
  cout << ans << endl;
  return 0;
}