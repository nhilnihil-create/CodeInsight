#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 3010;
int f[SIZEN][SIZEN * 2];
int A[SIZEN],B[SIZEN];
int id[SIZEN] = {0};
int N,T;
bool Cmp(const int &a,const int &b){return A[a]<A[b];}
int main(){
    scanf("%d%d",&N,&T);T--;
    for(int i = 1;i <= N;i++)scanf("%d%d",&A[i],&B[i]);
    for(int i = 1;i <= N;i++)id[i] = i;
    sort(id + 1,id + 1 + N,Cmp);
    memset(f,-1,sizeof f);
    f[0][0] = 0;
    int lim = 0;
    for(int i = 1;i <= N;i++){
        int x = id[i];
        f[i][0] = 0;
        for(int j = 1;j <= T + A[x];j++){
            f[i][j] = f[i-1][j];
            if(j >= A[x])f[i][j] = max(f[i][j],f[i-1][j-A[x]] + B[x]);
        }
    }
    int ans = 0;
    for(int i = 1;i <= T+A[id[N]];i++)ans = max(ans,f[N][i]);
    printf("%lld\n",ans);
}