#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=3009;
int x,t;
pair<int,int>p[N];
int dp[3009][6009];
int f(int i,int time)
{
    if (time>=t||i==x+1)
        return 0;
    if (dp[i][time]!=-1)
        return dp[i][time];
    return dp[i][time]=max(f(i+1,time),f(i+1,time+p[i].first)+p[i].second);
}
int main()
{
    FASTINOUT;
    cin>>x>>t;
    for (int i=1; i<=x; i++)
        cin>>p[i].first>>p[i].second;
    sort(p+1,p+x+1);
    memset(dp,-1,sizeof dp);
    cout<<f(1,0);
    return 0;
}
