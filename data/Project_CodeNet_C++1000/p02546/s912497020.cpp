#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  if (s[(int)s.size()-1] == 's') {
    s += "es";
  } else {
    s += "s";
  }
  cout << s << endl;
  return 0;
}