#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[5005][5005];
int f(int a,int b,int limit){
	int&ret = dp[a][b];
	if(~ret) return ret; 
	if(s[a]!=s[b]) return ret = 0;
	
	if(b==n-1 || a==limit) return ret = 1;
	return ret = 1+f(a+1,b+1,limit);
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>s;
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ans = max(ans,f(i,j,j-1));
		}
	}
	cout<<ans;
}