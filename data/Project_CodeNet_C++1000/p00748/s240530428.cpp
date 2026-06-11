#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
using namespace std;
#define ull unsigned long long
int memo[150];
int  dp[1000002];
int  dp2[1000002];
void inset(){
	dp[0]=0;
	fill(dp,dp+1000001,10000);
	fill(dp2,dp2+1000001,10000);
	dp[0]=0;
	dp2[0]=0;
	rep(i,1,200){
		memo[i]=i*(i+1)*(i+2),memo[i]/=6;
		rep(j,1,1000001)
			if(j-memo[i]>=0){
		if(dp[j]>dp[j-memo[i]]+1)dp[j]=dp[j-memo[i]]+1;
		if(memo[i]&1)if(dp2[j]>dp2[j-memo[i]]+1)dp2[j]=dp2[j-memo[i]]+1;
		}
	}
	//rep(i,1,1000001){
	//	if(dp2[i]==0){
	//	printf("[%d]%d\n",i,dp2[i]);
	//	break;
	//	}
	//}
}


int main(void){
	inset();
	int x;
	while(true){
		cin>>x;if(x==0)return(0);
		cout<<dp[x]<<" "<<dp2[x]<<endl;
	}

}