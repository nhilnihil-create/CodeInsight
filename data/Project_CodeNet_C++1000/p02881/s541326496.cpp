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
  for (int i = sqrt(n); i >= 1; i--) {
    if (n % i == 0) {
      cout << i + n / i - 2 << '\n';
      return 0;
    }
  }
}
