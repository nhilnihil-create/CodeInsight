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

  int N;
  cin >> N;

  long double total = 0;

  rep(i, N, 0) {
    int A;
    cin >> A;
    if (A == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (i == 0) {
      total = A;
    } else {
      total *= A;
    }
  }
  const int m = 1000000000000000000LL;

  if (total > m) {
    cout << -1 << endl;
    return 0;
  };

  cout << fixed << setprecision(0);
  cout << total << endl;
}
