#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define itn int

int main(void){
    int n,m;
    cin >> n >> m;
    int a[m];
    map<int,int> mp;
    for(int i = 0;i < m;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    ll mod = 1e9+7;
    vector<ll> dp(n+1,0);
    
    dp[0] = 1;
    if(mp[1] != 1)dp[1] = 1;
    
    for(int i = 2;i <= n;i++){
        dp[i] = max(dp[i],dp[i-1] + dp[i-2]) % mod;
        if(mp[i] == 1)dp[i] = 0;
    }
    
    cout << dp[n] << endl;
}