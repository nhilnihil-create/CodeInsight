#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  map<char, char> win;
  win['r'] = 'p';
  win['s'] = 'r';
  win['p'] = 's';

  map<char, int> pt;
  pt['r'] = r;
  pt['s'] = s;
  pt['p'] = p;

  string u = "";
  int max_p = 0;
  rep(i, n) {
    if (i - k < 0) {
      u += win[t[i]];
      max_p += pt[win[t[i]]];
      continue;
    }
    if (u[i-k] == win[t[i]]) {
      u += '*';
      continue;
    }
    u += win[t[i]];
    max_p += pt[win[t[i]]];
  }
  cout << max_p << endl;
  return 0;
}