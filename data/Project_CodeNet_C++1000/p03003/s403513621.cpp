#include<bits/stdc++.h>
using namespace std;

const int N = 2e3;

const int MOD = 1e9+7;

int n,m;
int a[N+5],b[N+5];

int memo[N+5][N+5];

int dp(int idx1, int idx2){
	if(idx1 > n || idx2 > m) return 0;
	int &ret = memo[idx1][idx2];
	if(ret!=-1) return ret;
	ret = dp(idx1+1,idx2);
	ret = (ret+dp(idx1,idx2+1))%MOD;
	ret  = (ret-dp(idx1+1,idx2+1)+MOD)%MOD;
	if(a[idx1] == b[idx2]){
		ret = (ret+dp(idx1+1,idx2+1)+1)%MOD;
	}
	return ret;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int ans = dp(1,1);
	printf("%d\n",(ans+1)%MOD);
	return 0;
}