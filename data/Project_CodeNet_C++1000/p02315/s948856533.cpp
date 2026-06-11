#if 0



#endif // 0

#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = (int) 1e5 + 10;
const int INF = (int) 0x3f3f3f3f;
typedef long long LL;
int N,W;
int dp[MAXN];

void work(){
    while(~scanf("%d%d",&N,&W)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            int v,w; scanf("%d%d",&v,&w);
            for(int j=W;j>=w;j--){
                dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
        printf("%d\n",dp[W]);
    }
}

int main(){
    work();
    return 0;
}

