#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

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
  for (auto kv : mp)
    if (kv.second == mx) cout << kv.first << '\n';
  return 0;
}