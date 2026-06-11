#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

long long  dfs(int curstep,int &n,set<int> &brok,vector<long long> &dp){
    if(curstep == n ) return 1;
    if(curstep>n || brok.count(curstep)) return 0;
    if(dp[curstep]!=-1) return dp[curstep];
    return dp[curstep] = (dfs(curstep+1,n,brok,dp)%mod + dfs(curstep+2,n,brok,dp)%mod)%mod;
}

int main(){
    int n,m;
    cin>>n>>m;
    set<int> broken;
    vector<long long> dp(n+1,-1);
    while(m--){
        int a;
        cin>>a;
        broken.insert(a);
    }
    cout<<dfs(0,n,broken,dp);
}