#include<bits/stdc++.h>
using namespace std;
int INF=1<<30,N,M,b,i,j,c,K,a[1<<10],S[1<<10];
int main(){
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>a[i];
		cin>>b;
		for(j=0;j<b;j++){
			cin>>c;
			S[i]+=1<<(c-1);
		}
	}
	K=1<<N;
	vector<int>dp(K,INF);
	dp[0]=0;
	for(i=1;i<K;i++)for(j=0;j<M;j++)dp[i]=min(dp[i],dp[i&~S[j]]+a[j]);
	cout<<(dp[K-1]==INF?-1:dp[K-1])<<endl;
}
