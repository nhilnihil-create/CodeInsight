#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int S;cin>>S;
    ll dp[3000];
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for(int i=0;i<=S;i++){
        dp[i+3]=dp[i+2]+dp[i];
        dp[i+3]%=M;
        //cout<<dp[i]<<endl;
    }
    cout<<dp[S]<<endl;
}
