#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += "0";
    int n = s.size();
    vector<vector<ll>> dp(1000005, vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,2){
            int now = (s[i] - '0') + j;
            rep(k,10){
                int ni = i+1, nj = 0;
                int r = k - now;
                if(r < 0){
                    nj = 1;
                    r += 10;
                }
                chmin(dp[ni][nj], dp[i][j]+k+r);
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
