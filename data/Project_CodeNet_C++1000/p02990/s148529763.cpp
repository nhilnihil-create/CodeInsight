#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

const int MAX = 10000;

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

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  COMinit();
  ll ans = 0;
  for (ll i = 1; i <= k; i++) {
    cout << (COM(n-k+1,i)%MOD)*(COM(k-1,i-1)%MOD)%MOD << endl;
  }
  return 0;
}