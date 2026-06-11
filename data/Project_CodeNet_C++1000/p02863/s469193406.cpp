#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;

int a[maxn];
int b[maxn];
int dp[3010][2];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=t-1;j>=0;j--)
        {
            if(j>=a[i])
            {

                dp[j][1]=max(dp[j][1],max(dp[j-a[i]][1]+b[i],dp[j][0]+b[i]));
                dp[j][0]=max(dp[j][0],dp[j-a[i]][0]+b[i]);

            }
            else
            {
                dp[j][1]=max(dp[j][1],dp[j][0]+b[i]);
            }
        }
    }
    cout<<dp[t-1][1]<<'\n';




}
