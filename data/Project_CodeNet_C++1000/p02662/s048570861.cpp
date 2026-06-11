#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
// const int MOD = 1e9+7;
const int MOD = 998244353;
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

ll dp[3010][3010];

int main()
{
    cout << fixed << setprecision(15);
    ll N, S;
    cin >> N >> S;

    Fill(dp, 0);

    vector<ll> A(N+1);
    for(ll i=1; i<=N; i++){
        cin >> A[i];
    }

    // for(ll i=0; i<N; i++){
    //     dp[i][0] = 1;
    // }
    dp[0][0] = 1;
    // cout << "a" << endl;
    
    for(ll i=1; i<=N; i++){
        for(ll k=0; k<=S; k++){
            if(k-A[i]<0){
                dp[i][k] = ((dp[i-1][k]%MOD)*2)%MOD;
            }
            else{
                dp[i][k] = ((((dp[i-1][k]%MOD)*2)%MOD + dp[i-1][k-A[i]])%MOD)%MOD;
            }
            // dp[i][k] = dp[i][k] % MOD;
        }
    }
    // for(ll i=0; i<=N; i++){
    //     for(ll j=0; j<=S; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][S] << endl;
    return 0;
}