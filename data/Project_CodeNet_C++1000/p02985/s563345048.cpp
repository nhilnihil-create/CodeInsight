#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll ans=1;
const int MAX = 510000;//階乗の配列数
const int MOD = 1000000007;

int k;
vector<int> to[100005];
  vector<int> deg(100005);
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

long long pr(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n-k] % MOD;
}

// mod. m での a の逆元 a^{-1} を計算する
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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void dfs(int v, int p=-1) {
  if(p==-1){
    ans*=pr(k, deg[v]+1);
    ans%=MOD;
  } else {
    ans*=pr(k-2, deg[v]-1);
    ans%=MOD;
  }
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,v);
  }
}

int main(){
  //ABC138D

  int n;
  cin >> n >> k;
  rep(i,n-1) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      to[a].push_back(b);
      to[b].push_back(a);
      deg[a]++;deg[b]++;
    }
    COMinit();
    dfs(0, -1);
    cout << ans << endl;
  return 0;
}
