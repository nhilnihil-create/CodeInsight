#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i= 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
const ll MOD = 1e9 + 7;


template<class T> inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
 //入力
int N;          //段数
int M;          //移動不可ノード数
vector<bool> issafe;    //移動不可ノード
vector<ll> dp(110000);  //DPテーブル

const ll INF = 1LL << 60;   //2^60で初期化

int main() {
    cin >> N >> M; //N= 階段の総数 M=移動が不可能な段数
    
    issafe.assign(N+1, true); //issafeをN個作成し、trueで初期化

    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        issafe[a] = false;  //壊れている段数をfalseに
    }

    //初期条件
    dp[0] = 1;
    if (issafe[1]) dp[1] = 1;

    //ループ、比較
    for (int i = 2; i <= N; ++i) {
        if (issafe[i-1]) dp[i] += dp[i - 1];
        if (issafe[i-2]) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[N] << '\n';

    return 0;
}