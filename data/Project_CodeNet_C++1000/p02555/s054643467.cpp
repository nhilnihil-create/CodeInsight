#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int MOD=1e9+7;
const int MAXN=1e2;
typedef long long ll;
int dp[2010];
int main()
{
    ios;
    int s;
    cin>>s;
    dp[0]=1;
    for(int i=0;i<=s;i++){
        for(int j=3;i+j<=s;j++){
            dp[i+j]=(dp[i+j]+dp[i])%MOD;
        }
    }
    cout<<dp[s]<<'\n';
    return 0;
}