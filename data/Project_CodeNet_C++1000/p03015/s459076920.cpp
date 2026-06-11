#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

ll dp[100005][2];

int main() {
    string s;cin>>s;
    int n = s.size();
    // dp[1][1]=2;
    // dp[2][0]=2;
    dp[0][1] = 1;
    rep(i,n) {
        dp[i+1][0] += dp[i][0] * 3;
        dp[i+1][0] %= MOD;
        if(s[i]=='1') {
            dp[i+1][0] += dp[i][1];
            dp[i+1][0] %= MOD;
            dp[i+1][1] += dp[i][1] * 2;
            dp[i+1][1] %= MOD;
        } else {
            dp[i+1][1] += dp[i][1];
            dp[i+1][1] %= MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD <<endl;
}