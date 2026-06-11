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
    return a/gcd(a, b) * b;
}

// 1~i番目まで見たときのj分以内での最大値
ll dp[3010][3010];


int main()
{
    cout << fixed << setprecision(15);
    ll N, T;
    cin >> N >> T;

    vector<P> A(N);

    REP(i, N){
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    ll ans = 0;
    REP(i, N){
        REP(j, T){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            ll nj = j + A[i].first;
            if(nj > T) continue;
            dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+A[i].second);
        }
        ans = max(ans, dp[i][T-1] + A[i].second);
    }

    cout << ans << endl;
    return 0;
}