#include<bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define ll long long int
ll mod=1e9+7;
ll dp[2005];
int main(){
	dp[0]=1;
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=2000;i++){
		dp[i]=(dp[i-1]+dp[i-3])%mod;
	}
	int s;
	while(cin>>s){
		if(s<3)cout<<"0"<<endl;
		else cout<<dp[s-3]<<endl;
	}
}
