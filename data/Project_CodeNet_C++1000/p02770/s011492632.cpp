#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *x,ll *y){
  ll tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

const int MAX = 510000;
const int MOD = 1000000007;

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

int main(){
  ll k,q;
  cin >> k >> q;
  vector<ll> vec(k);
  vector<ll> mov(k+1);
  vector<ll> sum_vec(k+1);
  rep(i,k){
    cin >> vec[i];
  }
  ll n,x,m;
  ll ans;
  rep(i,q){
    cin >> n >> x >> m;
    x %= m;
    ans = n-1;
    ll sum = 0;
    mov[0] = 0;
    sum_vec[0] = 0;
    REP(i,1,k+1){
      mov[i] = (mov[i-1] + vec[i-1] % m);
      if(vec[i-1] % m == 0){
        sum++;
      }
      if(mov[i] >= m){
        sum++;
        mov[i] %= m;
      }
      sum_vec[i] = sum;
    }
    n--;
    ans -= sum * (n / k);
    //cout << ans << endl;
    ans -= sum_vec[n%k];
    t1 = (n / k) * mov[k] + mov[n % k] + x;
    ans -= (t1 / m);
    cout << ans << endl;
  }
}