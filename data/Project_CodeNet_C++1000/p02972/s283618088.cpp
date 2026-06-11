#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
ll factorial(ll n) {
  if (n == 1) {
    return 1;
  }
  ll ans = factorial(n-1);
  return ans*n;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}
bool is_prime(ll n) {
  for (ll i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  return n != 1;
}
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow(x*x%mod, n/2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  vector <ll> res;
  vector <ll> sum(n, 0);
  for (ll i = n-1; i >= 0; i--) {
    if (sum.at(i)%2 != v.at(i)) {
      res.push_back(i+1);
      for (ll j = 1; j*j <= i+1; j++) {
        if ((i+1)%j == 0) {
          sum.at(j-1)++;
          if (j != (i+1)/j) sum.at((i+1)/j-1)++;
        }
      }
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  rep(i, res.size()) {
    if (i) cout << ' ' << res.at(i);
    else cout << res.at(i);
    if (i == res.size()-1) cout << endl;
  }
}