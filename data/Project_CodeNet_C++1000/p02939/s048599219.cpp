#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int f[Maxn][3],n;
char s[Maxn];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        f[i][1]=-500007,f[i][2]=-500007;
    f[1][1]=1;
    f[2][2]=1;
    if (s[1]!=s[2]) f[2][1]=2;
    for (int i=3;i<=n;i++)
    {
        f[i][1]=max(f[i][1],f[i-1][2]+1);
        if (s[i]!=s[i-1]) f[i][1]=max(f[i][1],f[i-1][1]+1);
        f[i][2]=max(f[i][2],f[i-2][1]+1);
        if ((s[i]!=s[i-2])||(s[i-1]!=s[i-3])) f[i][2]=max(f[i][2],f[i-2][2]+1);
    }
    printf("%d\n",max(f[n][1],f[n][2]));
    return 0;
}