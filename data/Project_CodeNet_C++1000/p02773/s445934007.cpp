/**
 *    author:  morato
 *    created: 25.08.2020 20:09:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> freq;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    freq[s]++;
  }
  int mx = 0;
  for (auto it = freq.begin(); it != freq.end(); it++) {
    mx = max(mx, it->second);
  }
  vector<string> v;
  for (auto it = freq.begin(); it != freq.end(); it++) {
    if (it->second == mx) {
      v.push_back(it->first);
    }
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << x << '\n';
  }
  return 0;
}