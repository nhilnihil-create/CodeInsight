#include<bits/stdc++.h>
using namespace std;
const int N=2003;
int n,m,ans,f1[N][N],f2[N][N],f3[N][N],f4[N][N];
char mp[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(mp[i][j]=='.')f1[i][j]=f1[i-1][j]+1,f2[i][j]=f2[i][j-1]+1;
    for(int i=n;i;i--)
    for(int j=m;j;j--)
    if(mp[i][j]=='.')f3[i][j]=f3[i+1][j]+1,f4[i][j]=f4[i][j+1]+1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(mp[i][j]=='.')ans=max(ans,f1[i][j]+f2[i][j]+f3[i][j]+f4[i][j]-3);
    printf("%d\n",ans);
}