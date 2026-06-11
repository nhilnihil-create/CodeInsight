#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll fac[MAX], finv[MAX], inv[MAX];

void nCrprep() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll nCr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

ll nCrcheep(ll n,ll r){
  if(r == 0) return 1;
  else if(r == 1) return n;
  else return nCrcheep(n-1,r-1)*n/r;
}

vector<pair<ll,ll>> prime_factorize(ll n){
  vector<pair<ll,ll>> res;
  
  for(ll i=2; i*i <= n; i++){
    if(n % i != 0) continue;
    
    ll ex = 0;
    while(n % i == 0){
      ex++;
      n /= i;
    }
    
    res.push_back({i,ex});
  }
  
  if(n != 1) res.push_back({n,1});
  
  return res;
  
}


struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};




int main(){
  ll n,m; cin >> n >> m;
  UnionFind UF(n);
  
  rep(i,m){
    ll a,b; cin >> a >> b; a--; b--;
    UF.unite(a,b);
  }
  
  ll ans = 0;
  
  rep(i,n){
    ans = max(ans,ll(UF.size(i)));
  }
  
  cout << ans << endl;
  
  
}