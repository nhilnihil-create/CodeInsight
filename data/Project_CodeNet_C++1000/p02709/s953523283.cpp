#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int dp[2010][2010];
int a[2010];
struct node
{
    int first;
    int second;
}c[5001];


bool cmp(node p1,node p2)
{
    return p1.second>p2.second;
}

int work(int now,int l,int r)
{
	if (l>r)  return c[now].second;
	if (dp[l][r]!= -1)  return dp[l][r];

	int f=work(now+1,l+1,r)+c[now].second*abs(c[now].first-l);
	int s=work(now+1,l,r-1)+c[now].second*abs(c[now].first-r);
	dp[l][r]=max(dp[l][r], max(f,s) );

	return dp[l][r];
}
signed main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i].second = a[i];
        c[i].first = i;
    }
    sort(c+1,c+1+n,cmp);
    cout<<work(1,1,n);
    /*
    for(int l=1;l<=n;l++)
    {
        for(int r=1;r<=n;r++)
        {
            if(l+r==n+1)
            {
                ans=max(ans,dp[l][r]);
            }
            cnt=l+r-1;
            dp[l+1][r]= max(dp[l+1][r],dp[l][r]+abs(c[cnt].first-l)*c[cnt].second);
            dp[l][r-1]= max(dp[l][r-1],dp[l][r]+abs(r - c[cnt].first)*c[cnt].second);
        }
    }*/
    //cout<<ans<<endl;
}