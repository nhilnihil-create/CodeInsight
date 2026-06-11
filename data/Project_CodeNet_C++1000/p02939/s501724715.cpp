#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s;
  cin >> s;

  int Z = s.size();
  vector<int> v(Z, 0);
  v[0] = 1;
  if (1 < Z) v[1] = s.at(0) == s.at(1) ? 1 : 2;
  if (2 < Z) v[2] = s.at(1) == s.at(2) ? 2 : v[1] + 1;
  rep(i,3,Z-1) v[i] = s.at(i) == s.at(i-1) ? v[i-3] + 2 : v[i-1] + 1;

  cout << v.back() << endl;
  return 0;
}
