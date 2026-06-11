#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;

int main() {
  string s,t;
  cin >> s;
  t = s;
  reverse(t.begin(), t.end());
  int cnt = 0;
  rep(i,s.size()) {
    if (s.at(i) != t.at(i)) cnt++;
  }
  if (cnt == 0) cout << 0 << endl;
  else cout << cnt / 2 << endl;
}
