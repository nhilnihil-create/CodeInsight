#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) a.begin(),a.end()

int main(){
	const long mod=1e9+7;
	int N,M;cin>>N>>M;
	int S[N],T[M];
	rep(i,0,N) cin>>S[i];
	rep(i,0,M) cin>>T[i];
	long dp[N][M]={};long sum[N][M]={};long temp=0;
	rep(i,0,M){
		if(S[0]==T[i]){
			dp[0][i]=1;
		}
        temp+=dp[0][i];
		sum[0][i]=temp;
	}temp=0;
	rep(i,0,N){
		if(S[i]==T[0]){
			dp[i][0]=1;
		}
        temp+=dp[i][0];
		sum[i][0]=temp;
	}
	rep(i,1,N){
		rep(j,1,M){
			if(S[i]==T[j]){
				dp[i][j]=sum[i-1][j-1]+1;
			}sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j]+mod)%mod;
		}
	}cout<<(sum[N-1][M-1]+1)%mod<<endl;
}