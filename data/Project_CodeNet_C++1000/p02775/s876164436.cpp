#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    string s;
    cin >> s ;

    ll n = s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        ll d = s[i-1]-'0';
        dp[i][0] = min(dp[i-1][0] + d, dp[i-1][1] + (10-d));
        dp[i][1] = min(dp[i-1][0] + (d+1), dp[i-1][1] + (9-d));
    }
    cout << dp[n][0] << endl;


    return 0;

}
