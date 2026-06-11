#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

int dp[100010][13];

signed main(){
    string s; cin >> s;
    int n = (int)s.length();
    reverse(ALL(s));
    if(s[0] != '?'){
        dp[0][s[0]-'0'] = 1;
    }else{
        rep(i,10) dp[0][i] = 1;
    }
    
    int placemod = 10;
    reps(i,1,n-1){
        if(s[i] != '?'){
            int d = s[i] - '0';
            rep(m,13){
                int t = mod(m + d * placemod, 13);
                dp[i][t] = mod(dp[i][t] + dp[i-1][m]);
            }
        }else{
            rep(d,10){
                rep(m,13){
                    int t = mod(m + d * placemod, 13);
                    dp[i][t] = mod(dp[i][t] + dp[i-1][m]);
                }
            }
        }
        placemod = (10 * placemod) % 13;
    }
    
    cout << dp[n-1][5] << endl;
}