#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll cnt_divisors(ll N) {
  ll res = 0;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res++;
      if (N/i != i) res++;
    }
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ll k = n;
      while(k % i == 0) k /= i;
      if (k % i == 1) ans++;
    }
  }
  ans += cnt_divisors(n-1);
  cout << ans << endl;
  return 0;
}
