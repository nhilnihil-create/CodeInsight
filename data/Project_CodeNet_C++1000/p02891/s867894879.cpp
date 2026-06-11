#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  int k;
  cin >> s >> k;

  int ls = 1;
  int ns = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) ++ls;
    if (s[i] != s[i-1] || i == s.size() - 1) {
      ns += ls / 2;
      ls = 1;
    } 
  }

  int lf = 1, lb = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) ++lf;
    else break;
  }
  for (int i = s.size() - 2; i >= 0; --i) {
    if (s[i] == s[i+1]) ++lb;
    else break;
  }

  ll min_ope;
  if (s[0] != s[s.size() - 1]) min_ope = (ll)k * ns;
  else if (lf == s.size()) min_ope = (ll)s.size() * k / 2;
  else {
    min_ope = (ll)k * ns + ((lf + lb) / 2 - lf / 2 - lb / 2) * (k - 1);
  } 
  cout << min_ope << endl;
  return 0;
}