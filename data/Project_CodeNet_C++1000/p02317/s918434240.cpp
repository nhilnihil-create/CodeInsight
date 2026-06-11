#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1e5+10,INF=1e9+4;

int dp[MAXN],N,ans=0;

int main(){
    scanf("%d",&N);
    fill(dp+1,dp+N+1,INF);
    for(int i=1;i<=N;i++){
        int temp;
        scanf("%d",&temp);
        auto l=lower_bound(dp+1,dp+1+i,temp);
        *l=temp;
        ans=max(ans,(int)(l-dp));
    }

    printf("%d\n",ans);

    return 0;
}
