#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<int> cnt(26);
  int ans = 0;
  rep(i, 4) {
    int t;
    t = s[i]-'A';
    if (cnt[t] == 1) {
      ans++;
    }
    cnt[t]++;
  }
  if (ans == 2) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}