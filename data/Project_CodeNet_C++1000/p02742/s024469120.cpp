#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, s = 1;
  cin >> n >> m;
  if (n != 1 && m != 1) {
    s = (n / 2 + n % 2) * (m / 2 + m % 2) + (n / 2) * (m / 2);
  }
  cout << s << '\n';
}
