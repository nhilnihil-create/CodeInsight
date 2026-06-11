#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>>dp(n,vector<ll>(13));
    vector<ll>rem({1, 10, 9, 12, 3, 4});
    reverse(s.begin(),s.end());
    if(s[0]=='?'){
        rep(i, 0, 10){
            dp[0][i] = 1;
        }
    }else{
        int r = s[0] - '0';
        dp[0][r] = 1;
    }
    rep(i, 1, n){
        if(s[i] == '?'){
            rep(j, 0, 10){
                rep(k, 0, 13){
                    int p = j*rem[i%6]%13;
                    p = (p+k)%13;
                    dp[i][p] += dp[i-1][k];
                    dp[i][p] %= mod;
                }
            }
        }else{
            int q = s[i]-'0';
            int p = q*rem[i%6]%13;
            rep(j, 0, 13){
                dp[i][(p+j)%13] += dp[i-1][j];
                dp[i][(p+j)%13] %= mod;
            }
        }
    }
    cout << dp[n-1][5] << endl;
}