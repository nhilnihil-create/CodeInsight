#include <bits/stdc++.h>
 
using namespace std;
#define M 1005
#define N 15
int a[M];
int b[M];
int c[M];
int dp[M][4500];
int n,m;
int mx;
 
int solve(int idx,int mask)
{
    if(idx == m)
    {
        if(mask == mx)
        {
            return 0;
        }
        return 1e9;
    }
 
    if(dp[idx][mask] != -1)
    {
        return dp[idx][mask];
    }
    int temp = mask | c[idx];
    int A = solve(idx + 1, temp) + a[idx];
    int B = solve(idx + 1, mask);
 
    return dp[idx][mask] = min(A,B);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    mx = (1<<n) - 1;
    for(int i = 0 ; i < m ; i++)
    {
        cin>>a[i]>>b[i];
        for(int j = 0 ; j < b[i] ; j++)
        {
            int x;
            cin>>x;
            c[i] |= (1<<(x - 1)) ;
        }
    }
    int ans = solve(0,0);
    cout<<((ans != 1e9)?ans:-1)<<endl;
 
    return 0;
}