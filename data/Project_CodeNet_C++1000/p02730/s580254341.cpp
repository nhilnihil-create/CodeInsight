#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  string sl = "", sr = "";
  for (int i = 0; i < (s.size() - 1) / 2; i++) {
    sl += s[i];
    sr += s[i + (s.size() - 1) / 2 + 1];
  }
  string rsl = sl;
  string rsr = sr;
  reverse(sl.begin(), sl.end());
  reverse(sr.begin(), sr.end());
  if (sl == rsr && sl == rsl && sr == rsr) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
