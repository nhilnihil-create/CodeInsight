#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 500;
LL f[SIZEN][SIZEN];
int N,K;
LL H[SIZEN];
int main(){
    scanf("%d%d",&N,&K);
    for(int i = 1;i <= N;i++)scanf("%d",&H[i]);
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= min(N-K,i);j++){
            for(int k = 0;k < i;k++)f[i][j] = min(f[i][j],f[k][j-1] + max(0LL,H[i] - H[k]));
        }
    }
    // for(int i = 1;i <= N;i++){
    //     for(int j = 0;j <= N-K;j++)printf("f[%d][%d] = %lld\n",i,j,f[i][j]);
    // }
    LL ans = 0x3f3f3f3f3f3f3f3fLL;
    for(int i = N-K;i <= N;i++)ans = min(ans,f[i][N-K]);
    printf("%lld\n",ans);
    return 0;
}