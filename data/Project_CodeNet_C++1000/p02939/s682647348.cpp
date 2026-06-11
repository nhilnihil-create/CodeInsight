#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    string s;
    cin >> s;
    ll n = s.length();
    vector<vector<ll>> dp(1000000,vector<ll>(2,-INF));
    dp[0][0] = dp[1][1] = 1;
    for(ll i = 0;i<n;i++){
        //1=>1
        if(s[i] != s[i+1])chmax(dp[i+1][0],dp[i][0] + 1);
        //2=>2
        if(i >= 2 && s.substr(i-2,2) != s.substr(i,2))chmax(dp[i+2][1],dp[i][1] + 1);
        //1 => 2
        chmax(dp[i+2][1],dp[i][0] + 1);
        //2 => 1
        chmax(dp[i+1][0],dp[i][1] + 1);
    }
    cout << max(dp[n-1][0],dp[n-1][1]) << endl;
    return 0;
}
/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/