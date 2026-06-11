#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  map<string, int> m;
  rep(i, n) ++m[s[i]];

  int e = 0;
  vector<string> str;
  for (auto itr = m.begin(); itr != m.end(); ++itr) e = max(e, itr->second);
  for (auto itr = m.begin(); itr != m.end(); ++itr) if (itr->second == e) str.push_back(itr->first);
  sort(str.begin(), str.end());
  rep(i, str.size()) cout << str[i] << endl;
  return 0;
}