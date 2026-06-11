#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

ll root, ans = 1, n, k;
vector < ll > fact(MAXN);
vector < vector < ll > > adj(MAXN, vector < ll > ());

ll pwr(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inv(ll a){
  return pwr(a, mod - 2);
}

ll comb(ll n, ll r){
  if(r > n){
    cout << 0 << endl;
    exit(0);
  }
  return (((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod;
}

void dfs(ll u, ll p){
  if(u == root){
    ans = (ans * ((fact[adj[u].size() + 1] * comb(k, adj[u].size() + 1)) % mod)) % mod;
  }else{
    ans = (ans * ((fact[adj[u].size() - 1] * comb(k - 2, adj[u].size() - 1)) % mod)) % mod;
  }
  for(auto to : adj[u]){
    if(to != p){
      dfs(to, u);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++) fact[i] = (i * fact[i - 1]) % mod;

  cin >> n >> k;
  for(int i = 0; i < n - 1; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(n == 1){
    cout << k << endl;
    return 0;
  }
  if(n == 2){
    cout << (k * (k - 1)) % mod << endl;
    return 0;
  }

  for(int i = 1; i <= n; i++){
    if(adj[i].size() != 1){
      root = i; break;
    }
  }

  dfs(root, -1);

  cout << ans << '\n';
}
