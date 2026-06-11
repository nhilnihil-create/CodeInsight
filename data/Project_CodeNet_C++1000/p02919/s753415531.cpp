#include <bits/stdc++.h>

using namespace std;
typedef long long Int;

int main()
{
  int n;
  set<int> p;
  vector< pair<int, int> > v;
  scanf("%d", &n);
  
  p.insert(0);
  p.insert(n + 1);
  
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v.emplace_back(x, i);
  }
  
  sort(v.rbegin(), v.rend());
  
  Int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i) {
      auto it = p.lower_bound(v[i].second);
      auto it2 = it; --it2;
      auto it3 = it; ++it3;
      
      int prv = *it2;
      int cur = v[i].second;
      int nxt = *it;
      
      if (it2 != p.begin()) {
        --it2;
      	ans += (Int)(n - i) * (nxt - cur) * (prv - *it2);
      }
      if (it3 != p.end()) {
        ans += (Int)(n - i) * (cur - prv) * (*it3 - nxt);
      }
    }
    p.insert(v[i].second);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}