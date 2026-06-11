#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int A;
int dp[2007];
int answer(int R)
{
    if(R==0) return 1;
    if(dp[R]!=-1) return dp[R];
    int ways = 0;
    for(int i=3;i<=A;i++)
    {
        if(i<=R)
            ways = (ways+answer(R-i))%mod;
    }
    return dp[R]=ways;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    cin >> A;
    memset(dp,-1,sizeof(dp));
    cout << answer(A) << endl;
    return 0;
}
