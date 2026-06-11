#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long double PI = acos(-1);
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
ll MOD = 1000000007;
ll fact(ll m) {
  if(m == 0 || m == 1) return 1LL;
  else return (m * fact(m-1LL)) % MOD;
}
bool custom(pair<ll, ll> a, pair<ll, ll> b) {
  if(a.first == b.first) return (a.second > b.second);
  else return a.first < b.first;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
  string L;
  cin >> L;
  vector<int> setted;
  for(int i=0;i<L.size();i++) {
    if(L[i] == '1') setted.emplace_back(i);
  }
  long long ln = L.size();
  long long n = setted.size();
  long long ans = 0;
  for(int i=0;i<n+1;i++) {
    if(i == 0) ans += modpow(2LL, n, MOD);
    else {
      ans += modpow(2LL, (long long)i-1LL, MOD) * modpow(3LL, ln - (long long)setted[i-1] - 1LL, MOD);
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
