#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1050][10000];
int maxx=1;
void solve(){
	int n,m,a,b,sta=0,tmp;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		maxx*=2;
	}
	maxx-=1;
	for(int i=0;i<=m;i++){
		for(int j=1;j<=maxx;j++){
			dp[i][j]=1e9;
		}
	}
	for(int t=1;t<=m;t++){
		sta=0;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++){
			scanf("%d",&tmp);
			sta=sta|(1<<(tmp-1));
		}
		for(int i=0;i<=maxx;i++){
			dp[t][i|sta]=min(min(dp[t-1][i|sta],dp[t][i|sta]),dp[t-1][i]+a);
		}
		for(int i=0;i<=maxx;i++){
			dp[t][i]=min(dp[t][i],dp[t-1][i]);
		}
	}
	if(dp[m][maxx]==1e9){
		printf("-1");
	}
	else{
		printf("%d",dp[m][maxx]);
	} 
}
signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}