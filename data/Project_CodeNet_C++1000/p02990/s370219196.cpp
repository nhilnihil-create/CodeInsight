#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


// 二項係数nCk mod pの計算-------------------------------------
const int MAX = 510000;

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

int main() {
  COMinit();
  int N,K; cin >>N >>K;
  int L = N-K; // 赤いボールの数
  // 連続して並ぶ青いボールが何グループあるか
  for (int i=1; i<=K; i++){
    // 青いボールのグループの間に最低1つずつは赤ボールを置く必要がある
    int l = L - (i-1);
    // 間に置く赤ボールが足りないなら不可能で0
    if (l < 0){ cout <<0 <<endl; continue; }

    // 青いボールについても各グループに最低1つは置かないとダメ
    int k = K - i;

    // 赤いボールはl個をi+1グループに0個以上置く必要がある
    // i個の仕切りとl個のボールを並べると考える
    // (l+i) C i = (L+1) C i通り
    
    // 青いボールはk個をiグループに0個以上置く必要がある
    // i-1個の仕切りとk個のボールを並べると考える
    // (k+i-1) C k = (K-1) C k 通り
    ll res = COM(L+1, i) * COM(K-1, k) % MOD;
    cout <<res <<endl;
  }
}