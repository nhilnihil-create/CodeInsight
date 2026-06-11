#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

struct Linear_basis {
  ll MN, a[65], tmp[65];
  void insert(ll x) {
    for(ll i = MN; ~i; i--) {
      if(x & (1ULL << i)) {
        if(!a[i]) { a[i] = x; return; }
        else x ^= a[i];
      }
      if(!i) break;
    }
  }
  ll qmax(ll res = 0) {
    for(ll i = MN; ~i; i--) {
        res = max(res, res ^ a[i]);
        if(!i) break;
    }
    return res;
  }
  Linear_basis() {
    memset(a, 0, sizeof(a));
    memset(tmp, 0, sizeof(tmp));
  }
} hhw;
const ll maxn = 1e5 + 5;
ll n, arr[maxn], cnt[65], ans;

int main() {
  scanf("%llu", &n); hhw.MN = 63;
  for(ll i = 1; i <= n; i++) scanf("%llu", &arr[i]);
  for(ll k = 0; k <= 63; k++)
    for(ll i = 1; i <= n; i++)
      cnt[k] ^= ((arr[i] >> k) & 1ULL);
  for(ll k = 0; k <= 63; k++) {
    if(!cnt[k]) continue;
    ans += (1ULL << k);
    for(ll i = 1; i <= n; i++)
      if((arr[i] >> k) & 1ULL)
        arr[i] ^= (1ULL << k);
  }
  for(ll i = 1; i <= n; i++)
    hhw.insert(arr[i]);
  ans += hhw.qmax() * 2ULL;
  printf("%llu\n", ans);
  return 0;
}