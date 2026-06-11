#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n; 
int attack[1005];
int cost[1005];
int dp[10005];
int f(int health){
	int&ret = dp[health];
	if(~ret) return ret;
	ret = INF; 
	for(int i=0; i<n; i++){
		if(attack[i]>=health) ret = min(ret,cost[i]);
		else ret = min(ret,cost[i]+f(health-attack[i]));
	}
	return ret;
}
int main(){
	int h;
	cin>>h>>n;
	for(int i=0; i<n; i++) cin>>attack[i]>>cost[i];
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	cout<<f(h);
}