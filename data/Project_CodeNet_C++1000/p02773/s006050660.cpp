#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, string>;

int main() {
  int n;
  map<string, int> mp;
  cin >> n;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  vector<P> v;
  for (auto m : mp) {
    v.push_back(P(m.second, m.first));
  }
  sort(v.begin(), v.end());
  int m = v.back().first;
  for (auto p : v) {
    if (m == p.first) {
      cout << p.second << endl;
    }
  }
  return 0;
}
