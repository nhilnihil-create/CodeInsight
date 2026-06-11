#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e16;
constexpr ll MOD = 1000000007;

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

#define rep(i, N) for(ll i=0; i<(N); ++i)

template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } else { return 0; }}
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } else { return 0; }}


ll max(ll a, ll b) {return a < b ? b : a; }
ll min(ll a, ll b) {return a > b ? b : a; }
double maxf(double a, double b) { return a < b ? b : a; }

template<typename T> inline string toString(const T &a) {
  ostringstream oss; oss << a; return oss.str();
}

ll gcd(ll x, ll y) { return x % y ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

/*
* 積が負になる数: 負数 * 正数
* 積が正になる数: 正数 * 正数 or 負数 * 負数
* 答えが0になる数: 0 * 何でも
*/

ll repeatSquaring(ll n, ll p, ll mod) {
  if(p == 0) return 1;
  if(p % 2 == 0) {
    ll t = repeatSquaring(n, p / 2, mod);
    return t * t % mod;
  } else {
    return (n * repeatSquaring(n, p - 1, mod)) % mod;
  }
}

ll comb(ll n, ll k, ll mod) {
  //分子
  ll res = 1;
  rep(i, k) res = res * (n - i) % mod;
  
  //分母（逆数にする前）
  ll bunbo = 1;
  rep(i, k) bunbo = bunbo * (k - i) % mod;
  
  res = (res * repeatSquaring(bunbo, mod - 2, mod)) % mod;
  return res;
}

//合わない！！デバッグ必要！
int main() {
  int N, M;
  
  cin >> N >> M;
  
  vector<vector<int>> points((N + 1)*3, vector<int>());
  //3分割して 0 -> 1, 1 -> 2, 2 -> 0とする
  //有向グラフなので，片方向の辺のみ追加
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    points[u*3].push_back(v*3+1);
    //points[v*3+1].push_back(u*3);
    
    points[u*3+1].push_back(v*3+2);
    //points[v*3+2].push_back(u*3+1);
    
    points[u*3+2].push_back(v*3);
    //points[v*3].push_back(u*3+2);
  }
  
  int S, T;
  cin >> S >> T;
  S = S * 3;
  T = T * 3;
  //S_0 -> T_0のルートを探す (BFS)
  
  queue<pair<int, int>> q;
  unordered_set<int> seen;
  q.push(make_pair(S, 0));
  seen.insert(S);
  int ct = -1;
  while(!q.empty()) {
    auto pr = q.front(); 
    int n = pr.first;
    if(n == T) {
      ct = pr.second;
      break;
    }
    q.pop();
    
    for(auto p : points[n]) {
      if(seen.find(p) == seen.end()) {
        q.push(make_pair(p, pr.second + 1));
        seen.insert(p);
      }
    }
  }
  
  cout << (ct == -1 ? -1 : ct / 3) << endl;
}

//1 4 4 6 7 9
/*
int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  
  //まず，正，0，負になるペアの個数を数える
  int posct = 0;
  int zeroct = 0;
  int negct = 0;
  rep(i, N) {
    if(A[i] < 0)  ++negct;
    if(A[i] == 0) ++zeroct;
    if(A[i] > 0)  ++posct;
  }
  
  //各符号の組
  int pos_pairct = (posct * posct - posct) / 2 + (negct * negct - negct) / 2;
  int neg_pairct = negct * posct;
  int zero_pairct = (zeroct * zeroct - zeroct) / 2 + (posct * zeroct + negct * zeroct);
  
  sort(A.begin(), A.end());
  
  //順番を区別していったん数えることにする
  //同じインデックス同士は掛けないが，別のインデックスで同じ数なら掛ける
  if(K <= neg_pairct) {
    //負の領域
    //負 * 正 で二分探索
    //負を全部正にして，全部ソートすれば良いのか．筆はなくて生徒みなせばよい．順番が逆になるくらいか
    // int mid = neg_pairct / 2;
    // while(true) {
    //   if(A) 
    // }
  } else if(K <= neg_pairct + zero_pairct) {
    //ゼロの領域
    cout << 0 << endl;
    return 0;
  } else {
    //正の領域
    //昇順
    
    //二分探索で解いてみる    
    int beginIndex = -1;
    rep(i, N) {
      if(A[i] > 0) beginIndex = i;
    }
    int endIndex = N - 1;
    
    int mid = (endIndex - beginIndex) / 2 + beginIndex;
    while(true) {
       
    }
    
  }
}
*/