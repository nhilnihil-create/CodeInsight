#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007

int dp[1000010][2][2],n; 
 
int fun(int i,int zero,int nine){
	int ans=0;
	if(i>=n){
		if(i==n&&zero&&nine){
			return(1);
		}
		return(0);
	}
	if(dp[i][zero][nine]!=-1){
		return(dp[i][zero][nine]);
	}
	for(int j=0;j<=9;j++){
		ans+=fun(i+1,(j==0)|zero,(j==9)|nine);
		ans%=M;
	}
	dp[i][zero][nine]=ans;
	return(ans);
} 
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
//	int n;
	cin >> n;
	memset(dp,-1,sizeof(dp));
	cout << fun(0,0,0) << endl;
}
