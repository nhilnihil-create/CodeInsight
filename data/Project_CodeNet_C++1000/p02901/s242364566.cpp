#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=5009;
int treasure,key,tre,a[N],coast[N],k,l,dp[N][N];
int f(int i,int total)
{
    if (i==key)
    {
        if (total==tre)
            return 0;
        return 1e9;
    }
    else if (dp[i][total]!=-1)
        return dp[i][total];
    return dp[i][total]=min(f(i+1,total),f(i+1,total|a[i])+coast[i]);
}
int main()
{
    FASTINOUT;
    cin>>treasure>>key;
    for (int i=0; i<treasure; i++)
    {
        tre=tre|(1<<i);
    }
    for (int i=0; i<key; i++)
    {
        cin>>coast[i]>>k;
        for (int j=0; j<k; j++)
        {
            cin>>l;
            l--;
            a[i]=a[i]|(1<<l);
        }
    }
    memset(dp,-1,sizeof dp);
    int ans=f(0,0);
    cout<<(ans==1e9?-1:ans);
    return 0;
}
