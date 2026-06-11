#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())


/* 二項係数 C(n,k) mod p を計算 */
const int MOD = 1000000007;
const int MAX = 201000;
long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  ll n; cin >> n;
  string s; cin >> s;
  ll ans = 1;
  //s[i]が白なら1, 黒なら0
  vector<ll> color(2*n,0);
  REP(i,2*n){
    if(s[i]=='W') color[i] = 1;
    //前処理
    if(i%2==0) color[i] = !color[i];
  }

  ll white = 0;
  REP(i,2*n){
    white += color[i];
    if(color[i]==0){
      (ans *= white) %= MOD;
      white--;
    }
  }
  if(white != 0){
    cout << 0 << endl;
    return 0;
  }
  (ans *= fac[n]) %= MOD;
  cout << ans << endl;
}