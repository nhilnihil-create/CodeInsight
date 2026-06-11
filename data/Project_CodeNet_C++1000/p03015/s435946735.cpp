#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[100010][2];

int main() { 
    string L; cin >> L;
    int len = L.size();
    rep(i, 100010)rep(j ,2) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i, len){
        if(L[i] == '0'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1] * 3 % MOD;
        }else{
            dp[i+1][0] = dp[i][0] * 2 % MOD;
            dp[i+1][1] = (dp[i][1] * 3 % MOD + dp[i][0]) % MOD;
        }
    }
    cout << (dp[len][0] + dp[len][1]) % MOD << ln;
}


