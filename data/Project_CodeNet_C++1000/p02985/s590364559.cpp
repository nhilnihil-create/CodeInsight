#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
const int MAX = 510000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;//a^n%mod
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
ll dfs(int key,int parent,int k,Graph &g){
      /*if(g[key].size()+1>k){
        cout << -244823571 << endl;
        return 0;
      }*/
      ll ans=1;
      ll o=k-1;
      if(parent==-1)o++;
      for(ll u: g[key]){
        if(u==parent)continue;
        o--;
        //cout << ans << endl;
        ans=(ans*o%MOD*dfs((int)u,key,k,g))%MOD;
        //cout << u << " " << dfs((int)u,key,k,g) << endl;
      }
      //cout << key << ans << endl;
      return ans;
    
}   
int main(){
  int n,k;
  cin >> n >> k;
  Graph g(n);
  rep(i,n-1){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  //rep(i,n)cout << g[i].size() << endl;
  cout << k*dfs(0,-1,k,g)%MOD<< endl;
}