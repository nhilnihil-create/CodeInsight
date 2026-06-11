#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i, 0, n) {
    string s;
    cin >> s;
    mp[s]++;
  }

  int mx = 0;
  for (auto kv : mp) mx = max(mx, kv.second);

  set<string> st;
  for (auto kv : mp)

    if (kv.second == mx) st.insert(kv.first);

  for (string s : st) cout << s << '\n';
  return 0;
}