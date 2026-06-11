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

const ll MAX = 10000;
vector <bool> color(MAX);
vector <ll> indeg(MAX);
vector <vector <ll>> v(MAX, vector <ll> ());
queue <ll> q;
vector <ll> res;

void bfs(ll n) {
  q.push(n);
  color.at(n) = 0;
  while (!q.empty()) {
    ll j = q.front(); q.pop();
    res.push_back(j);
    rep(k, v.at(j).size()) {
      ll tmp = v.at(j).at(k);
      indeg.at(tmp)--;
      if (indeg.at(tmp)==0 && color.at(tmp)) {
        color.at(tmp) = 0;
        q.push(tmp);
      }
    }
  }
  return;
}

void tsort(ll n) {
  rep(i, n) {
    color.at(i) = 1;
    indeg.at(i) = 0;
  }
  rep(i, n) {
    rep(j, v.at(i).size()) {
      ll tmp = v.at(i).at(j);
      indeg.at(tmp)++;
    }
  }
  rep(i, n) {
    if (indeg.at(i)==0 && color.at(i)) {
      bfs(i);
    }
  }
  rep(i, res.size()) {
    cout << res.at(i) << endl;
  }
  return;
}

int main() {
  ll n, m;
  cin >> n >> m;
  rep(i, m) {
    ll s, t;
    cin >> s >> t;
    v.at(s).push_back(t);
  }
  tsort(n);
}
