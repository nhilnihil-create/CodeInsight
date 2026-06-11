#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n,m,v,p;
  cin >> n >> m >> v >> p;

  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());

  int ok = -1, ng = n;

  auto is_good = [&]() {
    int mid = (ng + ok) >> 1;
    if(mid < p) return true;
    int val = a[mid] + m;
    if(val < a[p - 1]) return false;
    int sum = 0;
    sum += (p - 1) * m;
    sum += (n - mid) * m;
    for (int i = p - 1; i < mid; i++) {
      sum += min(m, max(0LL, val - a[i]));
    }
    return sum >= m*v;
  };

  while(abs(ng - ok) > 1) {
    int mid = (ng + ok) >> 1;
    if(is_good()) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok + 1 << '\n';
}