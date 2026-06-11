#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int ll;

int N;
ll activity[2005];
int indices[2005];

ll dp[2002][2002];

int comp(int a,int b){
    return activity[a]>activity[b];
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%lld",activity+i);
        indices[i]=i;
    }

    sort(indices+1,indices+N+1,comp);

    for(int i=1;i<=N;i++){
        int index=indices[i];
        for(int j=0;j<i;j++){
            int left=j,right=i-left-1;
            dp[left+1][right]=max(dp[left+1][right],activity[index]*(index-left-1)+dp[left][right]);
            dp[left][right+1]=max(dp[left][right+1],activity[index]*(N-right-index)+dp[left][right]);
        }
    }

    ll ans=0;
    for(int i=0;i<=N;i++) ans=max(ans,dp[i][N-i]);

    printf("%lld\n",ans);

    return 0;
}