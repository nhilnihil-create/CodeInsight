#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[1000005][2];

int main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    s += '0';
    int n = int(s.size());
    rep(i,n+1) rep(j,2) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) rep(j,2){
        int x = s[i] - '0';
        x += j;
        rep(a,10){
            int ni = i+1, nj = 0;
            int b = a - x;
            if(b<0){
                nj = 1;
                b += 10;
            }
            chmin(dp[ni][nj],dp[i][j]+a+b);
        }
    }
    cout << dp[n][0] << endl;
}