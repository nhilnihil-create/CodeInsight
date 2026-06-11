#include <bits/stdc++.h>
using namespace std;
int dp[100007]={},b[100007]={};
int mod = (int)(1e9+7);
int main(){
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i=0;i<m;i++){
        cin >> a[i];
        b[a[i]]=1;
    }
    dp[0] = 1;
    if(!b[1]) dp[1] = 1; 
    for(int i=0;i<n-1;i++){
        int c=dp[i+1],d=dp[i];
        if(b[i]) d=0;
        if(b[i+1]) c=0;
        dp[i+2] = (c+d)%mod;
        if(b[i+2]) dp[i+2] = 0;
    }
    cout << dp[n] << endl;
}
