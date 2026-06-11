#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long f[302][301];
int h[302];

int main()
{
    int n,k;scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&h[i]);
    h[0]=h[n+1]=0;

    for (int i=1;i<=n+1;++i){
        for (int j=0;j<=min(i-1,k);++j){
            f[i][j]=f[i-1][min(j,max(i-2,0))]+max(h[i]-h[i-1],0);
            for (int t=1;t<=j;++t)
                f[i][j]=min( f[i][j],f[i-t-1][j-t]+max(h[i]-h[i-t-1],0) );
            //printf("%d %d %d\n",i,j,f[i][j]);
        }
        if(i<=k) for (int j=i;j<=k;++j) f[i][j]=f[i][j-1];
    }

    printf("%lld\n",f[n+1][k]);
}


