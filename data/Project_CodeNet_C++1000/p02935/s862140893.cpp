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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<double> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  double s = a[0];
  for (auto &i : a) (s += i) /= 2;
  cout << s << '\n';
}
