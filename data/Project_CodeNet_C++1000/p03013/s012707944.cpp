#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n,m;cin>>n>>m;
    
    vi a(n,0);
    rep(i,m){
        int b;cin>>b;
        a[b]++;
    }
    
    vector<long long> dp(n+2,0);
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        if(a[i])continue;
        
        dp[i+2] += dp[i];
        dp[i+2] %= MOD;
        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}