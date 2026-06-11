#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll dp[100010];

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> ok(100010,true);
    rep(i,m){
        int a;
        cin>>a;
        ok[a]=false;
    }

    dp[0]=1;
    rep(i,n){
        if(!ok[i]) continue;
        dp[i+1]=(dp[i+1]+dp[i])%MOD;
        dp[i+2]=(dp[i+2]+dp[i])%MOD;
    }

    cout<<dp[n]<<endl;
}