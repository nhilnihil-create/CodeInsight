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
  vector<int> v = {105, 104, 103, 102, 101, 100};
  int n;
  cin >> n;
  for (auto &i : v) {
    while (n >= i && n % 100 >= i % 100) n -= i;
  }
  cout << (n == 0) << '\n';
}
