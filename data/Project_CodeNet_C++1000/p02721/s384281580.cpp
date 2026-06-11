#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,c,k,dp1[200005],dp2[200005];
char s[200005];

int main()
{
    scanf("%d%d%d%s",&n,&k,&c,s+1);
    dp1[0]=-0x3f3f3f3f,dp2[k+1]=0x3f3f3f3f;
    for(int i=1,cnt=1;i<=n;i++)
        if(s[i]=='o'&&i>dp1[cnt-1]+c) dp1[cnt++]=i;
    for(int i=n,cnt=k;i>=1;i--)
        if(s[i]=='o'&&i<dp2[cnt+1]-c) dp2[cnt--]=i;
    for(int i=1;i<=k;i++)
        if(dp1[i]==dp2[i]) printf("%d\n",dp1[i]);
    return 0;
}