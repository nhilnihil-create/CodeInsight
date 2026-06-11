#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef vector<int> vi;
const ll M = 1e9 + 7;

int main(void){
  int n;
  scanf("%d", &n);
  vi rp(n);
  rep(i, n){
    int p;
    scanf("%d", &p);
    p--; rp[p] = i;
  }

  multiset<ll> ms; ll ans = 0;
  ms.insert(-1); ms.insert(-1);
  ms.insert(n); ms.insert(n);
  rep(i, n){
    ll id = rp[n - 1 - i], l1, l2, r1, r2, x = n - i;
    ms.insert(id);
    auto it = ms.find(id);
    l2 = *(--it), l1 = *(--it);
    it = next(it, 2);
    r1 = *(++it), r2 = *(++it);
    ll v = (l2 - l1) * (r1 - id) + (r2 - r1) * (id - l2);
    ans += v * x;
  }

  printf("%lld\n", ans);

  return 0;
}
