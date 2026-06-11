#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  --a; --b; --c; --d;

  bool sunuke = true;
  bool funuke = true;
  for (int i = a; i < c; ++i) if (s[i] == '#' && s[i+1] == '#') sunuke = false;
  for (int i = b; i < d; ++i) if (s[i] == '#' && s[i+1] == '#') funuke = false;

  bool poss;
  if (c == d) poss = false;
  else if (c < d) {
    if (sunuke && funuke) poss = true;
    else poss = false;
  } else {
    bool skip = false;
    for (int i = b; i <= d; ++i) if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') skip = true;
    if (sunuke && funuke && skip) poss = true;
    else poss = false;
  }
  if (poss) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}