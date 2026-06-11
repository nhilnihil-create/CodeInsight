#include<stdio.h>
#include <algorithm>
using namespace std;

int a[2001],b[2001];
long long f[2001][2001];
const long long Mod=1e9+7;

int main()
{
    int n,m;
   // printf("%lld\n",(-1)%Mod);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int j=1;j<=m;++j) scanf("%d",&b[j]);

    f[0][0]=1;
    for (int i=1;i<=n;++i) f[i][0]=1;
    for (int j=1;j<=m;++j) f[0][j]=1;

    for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j){
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        if (a[i]==b[j]) f[i][j]+=f[i-1][j-1];
        f[i][j]+=Mod;        f[i][j]%=Mod;
    }
   // for (int i=1;i<=n;++i,printf("\n")) for (int j=1;j<=n;++j) printf("\t%lld",f[i][j]);
    printf("%lld\n",f[n][m]);

}

