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
  ll n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  vector <ll> f(n, 0);
  vector <ll> b(n, 0);
  ll f_c = 0, b_c = k;
  rep(i, n) {
    if (s.at(i) == 'o') {
      f_c++;
      f.at(i) = f_c;
      i += c;
    }
  }
  rep(i, n) {
    if (s.at(n-1-i) == 'o') {
      b.at(n-1-i) = b_c;
      b_c--;
      i += c;
    }
  }
  rep(i, n) {
    if (f.at(i)==b.at(i) && f.at(i)) cout << i+1 << endl;
    if (f.at(i) == k) break;
  }
}