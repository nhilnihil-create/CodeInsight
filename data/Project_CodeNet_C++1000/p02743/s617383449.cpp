#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define ii pair<int,int>
#define fi first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define all(x) (x).begin(),(x).end()

#define sqr(x) ((x)*(x))

signed main() {
#ifdef _DEBUG
  freopen("in", "r", stdin);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  unsigned long long a, b, c;
  cin >> a >> b >> c;
  long long lla = a, llb = b, llc = c;
  if (llc - lla - llb < 0LL) cout << "No" << '\n';
  else cout << (a * b * 4ULL < sqr(c - a - b) ? "Yes" : "No") << '\n';
}
