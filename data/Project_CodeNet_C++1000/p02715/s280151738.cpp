#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

long long modpow(long long a, long long n, long long m) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }

  return res;
}

int main() {
  ll n,k;
  cin >> n >> k;

  unordered_map<ll, ll> hashMap;
  vector<ll> cnt(k+1);
  for (ll i = k; i > 0; --i) {
    ll cp = i, total = 0;
    ll tmp = 0;
    do {
      total += 1;
      cp += i;
      if (cp > k) break;
      tmp += cnt[cp];
      tmp %= mod;
    } while (cp <= k);

    cnt[i] += modpow(total, n, mod) + (mod - tmp);
    cnt[i] %= mod;
  }

  ll ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += cnt[i] * i;
    ans %= mod;
  }
  cout << ans << endl;
}