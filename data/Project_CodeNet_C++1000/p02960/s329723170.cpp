#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    string s;   cin >> s;
    ll n=s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(13, 0));
    dp[0][0] = 1;
    rep(i, n){
        rep(j, 13){
            rep(k, 10){
                if(s[i]=='?' || s[i]-'0'==k){
                    ll md = (j*10+k)%13;
                    dp[i+1][md] += dp[i][j];
                    dp[i+1][md] %= MOD;
                }
            }
        }
    }
    
    cout << dp[n][5] << endl;
}
