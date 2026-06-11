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

long long modPow(long long x, long long a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    long long t = modPow(x, a / 2);
    return (t * t) % MOD;
}

long long modInv(long long x) {
    return modPow(x, MOD - 2);
}

long long modPerm(long long n, long long k) {
    long long ret = 1;
    for (long long i = 0; i < k; i++) {
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll b_num = k-1, b_sep = 0, r_num = n-k, r_sep = 1;
    REP(i, k){
        if(b_num < 0 || r_num < 0){
            cout << 0 << endl;
            continue;
        }
        ll b = modPerm(b_num+b_sep, b_num+b_sep) * modInv((modPerm(b_num, b_num)*modPerm(b_sep, b_sep))%MOD);
        ll r = modPerm(r_num+r_sep, r_num+r_sep) * modInv((modPerm(r_num, r_num)*modPerm(r_sep, r_sep))%MOD);
        b %= MOD;
        r %= MOD;
        cout << (b * r) % MOD << endl;
        b_num--;
        b_sep++;
        r_num--;
        r_sep++;
    }
    return 0;
}