#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<long,int>A[2000];
long dp[2001][2001];
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A,A+N);
	reverse(A,A+N);
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			int k=N-(i-j);
			dp[j+1][k]=max(dp[j+1][k],dp[j][k]+A[i].first*abs(A[i].second-j));
			dp[j][k-1]=max(dp[j][k-1],dp[j][k]+A[i].first*abs(A[i].second-(k-1)));
		}
	}
	long ans=0;
	for(int i=0;i<=N;i++)
                    ans=max(ans,dp[i][i]);
	cout<<ans<<endl;
}
