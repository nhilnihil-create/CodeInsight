
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 14 August 2020 01:58:23 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;
const int mod = 1e9+7;

int expo(int a, int b){
    if(b == 0){
        return 1;
    }
    int ans = expo((a*a)%mod,b/2);
    if(b%2){
        return (a*ans)%mod;
    }
    return ans%mod;
}

void solve(){
    int n,k;
    cin>>n>>k;
    
    int ans = 0;
    vector<int> dp(k+1);
    
    for(int i=k; i>=1; --i){
        int t = k/i;
        int curans = expo(t,n);
        curans %= mod;
        int minus = 0;
        for(int j=2*i; j<=k; j+=i){
            minus += dp[j];
            minus %= mod;
        }
        dp[i] = (curans-minus+mod)%mod;
        //ans += (curans-minus+mod)%mod;
        ans += (dp[i]*i)%mod;
        ans %= mod;
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}
