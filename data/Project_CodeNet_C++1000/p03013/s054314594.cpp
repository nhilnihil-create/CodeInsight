#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) ll(x.size()) //sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB emplace_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    REP(i, m) cin >> a[i];
    vector<ll> dp(n+1, 0);
    vector<bool> oks(n, true);
    REP(i, m) oks[a[i]] = false;
    dp[0] = 1;
    dp[1] = 1;
    if(oks[1] == false) dp[1] = 0;
    REP(i, n-1){
        dp[i+2] = dp[i+1] + dp[i];
        dp[i+2] %= MOD;
        if(oks[i+2] == false) dp[i+2] = 0;
    }
    cout << dp[n];
    return 0;
}