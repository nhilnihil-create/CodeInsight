#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N=3e2+10;
const ll INF=1e18+10;

ll dp[MAX_N][MAX_N],H[MAX_N];
int N,K,M;

int main(){
	for(int i=0;i<MAX_N;i++) for(int j=0;j<MAX_N;j++) dp[i][j]=INF;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%lld",&H[i]);
	if(N==K){
		printf("0\n");
		return 0;
	}
	K=N-K; 
	for(int i=0;i<N;i++){
		dp[i][1]=H[i];
		for(int k=2;k<=K;k++){
			for(int j=0;j<i;j++){
				dp[i][k]=min(dp[i][k],dp[j][k-1]+(H[i]>H[j]?H[i]-H[j]:0));
			}
		}
	}
	ll ans=INF;
	for(int i=0;i<N;i++) ans=min(ans,dp[i][K]);
	printf("%lld\n",ans);
	return 0;
} 