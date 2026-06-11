#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define revrep(i,n,g) for (int i = n - 1; i >= g; i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<ll> pow_list(int n, int k, ll mod) {
  vector<ll> rtn(k + 1,0);
  rtn[1] = 1;
  rep(i,2,k + 1) {
    rtn[i] = modpow(i,n,mod);
  }
  return rtn;
}

ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  int n,k;
  cin >> n >> k;
  ll p = 1000000007;
  vector<ll> line(k + 1,0);
  ll ans = 0;
  vector<ll> pl = pow_list(n,k,p);
  revrep(i, k + 1, 1) {
    ll a = pl[k / i];
    ll b = 0;
    for (int j = i * 2; j <= k; j += i) {
      b += line[j];
      b %= p;
    }
    line[i] = mod(a - b, p);

    ans += (line[i] * i) % p;
    ans %= p;
  }
  cout << ans << endl;
  return 0;
}
