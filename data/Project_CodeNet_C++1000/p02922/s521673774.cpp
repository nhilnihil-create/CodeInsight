#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << ceil((double)(b - 1) / (a - 1)) << '\n';
  return 0;
}
