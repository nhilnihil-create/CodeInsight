#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int ng[100010];
ll dp[100010];

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a;
        cin>>a;
        ng[a]=1;
    }

    dp[0]=1;
    rep(i,n){
        if(ng[i+1]) continue;
        dp[i+1]=(dp[i+1]+dp[i])%MOD;
        if(i-1>=0) dp[i+1]=(dp[i+1]+dp[i-1])%MOD;
    }
    
    cout<<dp[n]<<endl;
}
