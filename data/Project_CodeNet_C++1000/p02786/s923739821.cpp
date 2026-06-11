#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

map<int, int> m;

int cal(int h) {
  if (m[h]) return m[h];
  return m[h] = 1 + cal(h / 2) * 2;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int h;
  cin >> h;
  m[1] = 1;
  cout << cal(h) << '\n';
}
