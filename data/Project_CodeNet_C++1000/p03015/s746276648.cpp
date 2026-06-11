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
    
    Fill(dp, 0);
    dp[0][0] = 1; //初期条件

    for(int i = 0; i < l; i++){
        for(int smaller = 0; smaller < 2; smaller++){
                if(L[i] == '1'){
                    if(smaller){
                        dp[i+1][1] += dp[i][1] * 3; 
                        dp[i+1][1] = dp[i+1][1]%MOD;
                    }
                    else{
                        dp[i+1][1] += dp[i][0];
                        dp[i+1][1] = dp[i+1][1]%MOD;
                        dp[i+1][0] += dp[i][0]*2;
                        dp[i+1][0] = dp[i+1][0]%MOD;
                    }
                }
                if(L[i] == '0'){
                    if(smaller){
                        dp[i+1][1] += dp[i][1] * 3; 
                        dp[i+1][1] = dp[i+1][1]%MOD;
                    }
                    else{
                        dp[i+1][0] += dp[i][0];
                        dp[i+1][0] = dp[i+1][0]%MOD;
                    }
                }
        }
    }

    cout << (dp[l][0] + dp[l][1]) % MOD << endl;
    return 0;
}