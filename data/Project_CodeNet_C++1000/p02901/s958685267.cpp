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

ll dp[1100][5000];

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    vector<ll> A(M), B(M), C(M, 0); // c はビットで表す

    REP(i, M){
        cin >> A[i] >> B[i];
        REP(j, B[i]){
            ll t;
            cin >> t;
            t--;
            C[i] += (1<<t);
        }
    }
    
    // REP(i, M){
    //     cout << C[i] << endl;
    // }
    // Fill(dp, INF);
    REP(i, 1100){
        REP(j, 5000){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    // cout << 1 << endl;
    for (ll i=0; i<M; ++i) {
        for (int j=0; j<(1<<N); ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            
            ll nj = j | C[i];
            dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + A[i]);
        }
    }

    // cout << 2 << endl;
    if(dp[M][(1<<N)-1] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[M][(1<<N)-1] << endl;
    // cout << INF << endl;
    return 0;
}