#include <bits/stdc++.h>
#define rep(i, n, init) for (int i = init, len = (n); i < len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define _GLIBCXX_DEBUG
#define int long long
#define float long double
#define len(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;

template <class Key, class Value>
pair<Key, Value> findMaxValuePair(unordered_map<Key, Value> const &x) {
  return *max_element(
      x.begin(), x.end(),
      [](const pair<Key, Value> &p1, const pair<Key, Value> &p2) { return p1.second < p2.second; });
}

string padStart(int target, int len, char padString) {
  ostringstream ss;
  ss << setfill(padString) << right << setw(len) << target << flush;
  return ss.str();
}

bool isEven(const int &n) {
  return !(n & 1);
}

int ctoi(const char c) {
  return ('0' <= c && c <= '9') ? (c - '0') : -1;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A;
  float B;

  cin >> A >> B;

  cout << fixed << setprecision(0);
  cout << (int)((A * (B * 1000)) / 1000) << endl;

  return 0;
}
