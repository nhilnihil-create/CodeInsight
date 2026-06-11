#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N=3e2+10;
const ll INF=1e18+10;

ll dp[MAX_N][MAX_N][MAX_N],H[MAX_N];
int N,K,M;

int main(){
	for(int i=0;i<MAX_N;i++) for(int j=0;j<MAX_N;j++) for(int k=0;k<MAX_N;k++)
		dp[i][j][k]=INF;
	scanf("%d%d",&N,&K); M=N;
	for(int i=0;i<N;i++) scanf("%d",&H[i]);
	bool flag=false;
	for(int i=0;i<N;i++) if(H[i]==0) flag=true;
	if(!flag) H[M++]=0;
//	for(int i=0;i<M;i++) printf("%d ",H[i]); printf("\n");
	dp[0][0][0]=H[0];
	if(K>0) for(int i=1;i<=N;i++) dp[0][1][i]=H[i];
	for(int i=1;i<N;i++){
		dp[i][0][i]=min(dp[i][0][i],dp[i-1][0][i-1]+(H[i]>H[i-1]?H[i]-H[i-1]:0));
		for(int j=1;j<=K;j++){
			for(int k=0;k<M;k++){
			//	cout<<dp[i][j][k]<<endl;
				if(i==k){
					for(int fr=0;fr<M;fr++)
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][fr]+(H[i]>H[fr]?H[i]-H[fr]:0));
				}
				else{			
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k]);	
					//	dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][i-1]);
				}
			//	cout<<dp[i][j][k]<<endl;
			}
		}
	}
	ll ans=INF;
	for(int i=0;i<=K;i++) for(int j=0;j<M;j++)
		ans=min(ans,dp[N-1][i][j]);
	printf("%lld\n",ans);
	return 0;
}
