#include <iostream>
#include <utility>
#include <climits>
#include <numeric>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
void solve(int n){
	long dp[10][10],ans=INT_MAX,ans2;
	rep(i,10) rep(j,10) dp[i][j]=INT_MAX;

	rep(i,n){
		int f,t,l;
		cin>>f>>t>>l;
		dp[f][t]=l;dp[t][f]=l;
		dp[i][i]=0;
	}

	rep(k,10) rep(i,10) rep(j,10) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	int numofnINF=0;

	rep(i,10) if(dp[0][i]!=INT_MAX) numofnINF++;

	rep(i,10){
		long acc=0;
		rep(j,numofnINF) acc+=dp[i][j];
		if(ans>acc){ans=acc;ans2=i;}
	}
	cout<<ans2<<' '<<ans<<endl;
	return;
}

int main(){
	int c;
	cin>>c;
	while(c){
		solve(c);
		cin>>c;
	}
	return 0;
}