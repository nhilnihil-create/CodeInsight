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
  ll n, K;
  cin >> n >> K;
  vector<vector<int>> g(n);
  vector<bool> seen(n);
  for(int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<ll> k1(K);
  vector<ll> k2(K);
  for(int i=0;i<K;i++) {
    if(i == 0) k1[i] = 1;
    else k1[i] = k1[i-1] * (K-i) % MOD;;
  }
  for(int i=0;i<K-1;i++) {
    if(i == 0) k2[i] = 1;
    else k2[i] = k2[i-1] * (K-i-1) % MOD;
  }
  queue<int> que;
  ll ans = K;
  bool yes = true;
  que.emplace(0);
  while(!que.empty()) {
    int node = que.front();que.pop();
    if(seen[node]) continue;
    seen[node] = true;
    ll deg = g[node].size();
    if(deg > K-1) {
      yes = false;
      break;
    }
    if(node == 0) ans = ans * k1[deg] % MOD;
    else {
      deg--;
      ans = ans * k2[deg] % MOD;
    }
    for(auto&el : g[node]) que.emplace(el);
  }
  if(yes) cout << ans << endl;
  else cout << 0 << endl;
}
