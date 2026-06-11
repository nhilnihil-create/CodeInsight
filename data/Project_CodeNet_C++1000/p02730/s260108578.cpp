#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = (s.length() - 1) / 2;
  string rs = s, fs = s.substr(0, l), ss = s.substr(l + 1, l), rfs = fs, rss = ss;
  reverse(rs.begin(), rs.end());
  reverse(rfs.begin(), rfs.end());
  reverse(rss.begin(), rss.end());
  cout << ((s == rs && fs == rfs && ss == rss) ? "Yes" : "No") << endl;
}