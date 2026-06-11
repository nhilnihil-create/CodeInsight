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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  multiset<int> s(all(a));
  for (int i = 0; i < n; i++) {
    s.erase(s.find(a[i]));
    cout << *prev(s.end()) << '\n';
    s.insert(a[i]);
  }
}
