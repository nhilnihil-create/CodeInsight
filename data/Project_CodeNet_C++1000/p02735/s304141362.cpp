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

// 探索用の組み合わせ表現
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    vector<vector<char>> S(H+1, vector<char>(W+1));

    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            cin >> S[i][j];
        }
    }

    vector<vector<ll>> dp(H+1, vector<ll>(W+1, INF));

    if(S[1][1] == '#') dp[1][1] = 1;
    if(S[1][1] == '.') dp[1][1] = 0;

    REP(i, H+1){
        dp[i][0] = 0;
    }
    REP(i, W+1){
        dp[0][i] = 0;
    }

    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            for(ll dir = 0; dir < 2; dir++) {
                ll ni = i + dx[dir], nj = j + dy[dir];
                if (ni > H || nj > W) continue;
                ll add = 0;
                if (S[ni][nj] == '#' && S[i][j] == '.') add = 1;
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + add);
            }
        }
    }

    cout << dp[H][W] << endl;
    return 0;
}