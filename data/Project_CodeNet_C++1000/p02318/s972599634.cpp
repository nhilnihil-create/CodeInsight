#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9+7));
    rep(i,m)dp[0][i] = i;
    rep(i,n)dp[i][0] = i;
    rep(i,n)rep(j,m){
        if(s[i]==t[j])chmin(dp[i+1][j+1],dp[i][j]);
        chmin(dp[i+1][j+1],dp[i+1][j]+1);
        chmin(dp[i+1][j+1],dp[i][j+1]+1);
        chmin(dp[i+1][j+1],dp[i][j]+1);
    }
    /*
    rep(i,n+1){
        rep(j,m+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][m] << endl;
}
