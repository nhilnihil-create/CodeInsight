#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
const int sz=1e6+10,mod=1e9+7;
ll n,dp[sz][2][2];
// 행: 0이 없을 때, 있을 때
// 열: 9가 없을 때, 있을 때

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin>>n;
    dp[1][0][0]=8;
    dp[1][0][1]=1;
    dp[1][1][0]=1;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=n;++i){
        dp[i][0][0]=(dp[i-1][0][0]*8)%mod;
        dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][0][1]*9)%mod;
        dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][1][0]*9)%mod;
        dp[i][1][1]=(dp[i-1][0][1]+dp[i-1][1][0]+dp[i-1][1][1]*10)%mod;
    }
    cout<<dp[n][1][1]<<endl;
    return 0;
}
