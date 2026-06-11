#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZEN = 300010;
LL C[SIZEN] = {0};
LL D[SIZEN] = {0};
LL ans[SIZEN] = {0};
int N;
int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N;i++){
        int x;scanf("%d",&x);
        C[x]++;
    }
    for(int i = 1;i <= N;i++){
        D[C[i]]++;
    }
    for(int i = 1;i <= N;i++)D[i] += D[i-1];
    LL g = 0;
    memset(ans,-1,sizeof ans);
    ans[N+1] = 0;
    for(int i = 1;i <= N;i++){
        g = g + (D[i]-D[i-1]) * i;
      //  printf("g = %d , D[%d] = %d\n",g,i,D[i]);
        ans[(g + (D[N] - D[i] )*i)/i ] = i;
    }
    for(int i = N;i >= 1;i--){
        if(ans[i] == -1)ans[i] = ans[i+1];
        else continue;
    }
    for(int i = 1;i <= N;i++)printf("%d\n",ans[i]);printf("\n");
    getchar();getchar(); 
    return 0;

}