#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(){
    int n,m;
    cin >> n >> m;
    
    ll mod = 1e9+7;
    ll dp[n+1];
    rep(i,n+1)dp[i] = 0;
    dp[0] = dp[1] = 1;
    
    int a[m];
    map<int,int> mp;
    rep(i,m){
        cin >> a[i];
        mp[a[i]--]++;
    }
    
    dp[0] -= mp[0];
    dp[1] -= mp[1];
    
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
        
        if(mp[i] > 0)dp[i] = 0;
    }
    cout << dp[n] << endl;
}