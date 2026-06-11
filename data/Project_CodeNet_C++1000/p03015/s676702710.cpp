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

ll dp[100010][2];
// i : 調べている桁
// smaller : 対象の数字未満であることが確定しているならば1、そうでなければ0

int main()
{
    cout << fixed << setprecision(15);
    string L;
    cin >> L;

    ll l = L.size();  //Lの長さ
    
    ll ans = 1;
    ll pow3 = 1;

    reverse(L.begin(), L.end());
    for(ll i=0; i<l; i++){
        if(L[i] == '1'){
            ans = ((ans*2)%MOD + pow3) % MOD;
        }
        pow3 = (3*pow3) % MOD;
    }
    cout << ans << endl;
    return 0;
}