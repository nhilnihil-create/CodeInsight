#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int c = 1;
  string t = s.substr(0, 1);
  for (int i = 1; i < s.size(); i++) {
    string d = s.substr(i, 1);
    if (d != t) {
      c++;
      t = d;
    }
    else if (i != s.size() - 1) {
      c++;
      i++;
      t = s.substr(i, 2);
    }
  }
  cout << c << '\n';
}
