#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000005;
int n;
int dp[MAXN][2][2];
int dfs(int len,bool const1,bool const2){
    if(len==n){
        if(const1 && const2)
        return 1;
        else
        return 0;
    }
    if(dp[len][const1][const2] != -1)
    return dp[len][const1][const2];
    ll sum=0;
    for(int i=0;i<=9;i++){
        bool a=const1,b=const2;
        if(i==0)
        a=1;
        if(i==9)
        b=1;
        sum=((sum%MOD)+(dfs(len+1,a,b)%MOD))%MOD;
    }
    return dp[len][const1][const2]=sum%MOD;
    
}


int main() {
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<dfs(0,0,0)%MOD<<endl;
    return 0;
}