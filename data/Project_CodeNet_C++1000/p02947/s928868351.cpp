#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  ll cnt = 0;
  for (auto mpp : mp) {
    if (mpp.second == 1) continue;
    ll m = mpp.second;
    ll c = m * (m - 1) / 2;
    cnt += c;
  }

  cout << cnt << endl;
  return 0;
}
