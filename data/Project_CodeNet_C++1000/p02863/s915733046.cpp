#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll n,t;cin>>n>>t;
   vector<vector<ll>>dp(n+1,vector<ll>(6100,0));
   vector<vector<ll>>rp(n+1,vector<ll>(6100,0));
   vector<ll>a(n);
   vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i]>>b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            dp[i+1][j+a[i]]=max(dp[i][j]+b[i],dp[i][j+a[i]]);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }
    reverse(all(a));
    reverse(all(b));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            rp[i+1][j+a[i]]=max(rp[i][j]+b[i],rp[i][j+a[i]]);
            rp[i+1][j]=max(rp[i][j],rp[i+1][j]);
        }
    }
    reverse(all(b));
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            ans=max(ans,dp[i][j]+rp[n-i-1][t-j-1]+b[i]);
//            cout <<i<<" "<<j<<" "<<dp[i][j]<<" "<<rp[n-i-1][t-j-1]<<" "<<b[i]<<endl;
        }
    }
    cout <<ans <<endl;
   return 0;
}

