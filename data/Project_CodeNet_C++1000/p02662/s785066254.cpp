#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define REP(i,n) for(ll i = 0 ; i < n ; i ++)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
#define mod 998244353
int main() {
    ll n,s;
    cin >> n >> s ;
    ll a[n];
    REP(i,n) cin >> a[i] ;
    ll dp[n+1][s+1] ;
    memset(dp,0,sizeof dp) ;
    dp[0][0] = 1;
    for(int i = 0 ; i < n ; i ++) {
        for(int j = 0 ; j <= s ; j ++) {
            dp[i+1][j] = (dp[i+1][j]+2*dp[i][j])%mod;
            if(j + a[i] <= s) {
                dp[i+1][j+a[i]] = (dp[i+1][j+a[i]] + dp[i][j])%mod;
            }
        }    
    }
    cout << dp[n][s] << endl;
    return 0; 
}