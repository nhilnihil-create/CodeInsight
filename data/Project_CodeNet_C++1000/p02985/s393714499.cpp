#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll N, K;

ll fact(ll n){
    if(n ==1) return 1;
    if(n == 0) return 1;

    return (n * fact(n-1)) % MOD;
}

const int MAX = 1000000;
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

vector<bool> seen;  // 訪問済みの点
ll ans = 1;

// BFSのための再帰関数
void dfs(const Graph &G, int v, int counter) {
    seen[v] = true;
    // dist[v] = counter;

    ll child = G[v].size();
    // cout << v << " " << child << endl;

    if(counter == 0){
        ans *= COM(K-1, child);
        ans = ans % MOD;
        ans *= fact(child);
        ans = ans % MOD;
    }
    else{
        ans *= COM(K-2, child-1);
        ans = ans % MOD;
        ans *= fact(child-1);
        ans = ans % MOD;
    }
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, counter+1); // 再帰的に値を追加していく
    }
}

int main()
{
    cout << fixed << setprecision(15);
    cin >> N >> K;

    // 前処理
    COMinit();

    // REP(i, K){
    //     cout << (COM(N-K+1, i+1) % MOD * COM(K-1, i) % MOD)% MOD << endl;
    // }

    // グラフ
    Graph G(N);
    seen.assign(N, false);

    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    dfs(G, 0, 0);

    ans *= K;
    cout << ans % MOD << endl;

    return 0;
}