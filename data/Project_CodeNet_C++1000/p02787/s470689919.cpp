#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n;
int dp[10005];
int damage[1005];
int cost[1005];
int f(int health){
	if(health<=0) return 0;
	int&ret = dp[health];
	if(~ret) return ret;
	ret = INF;
	for(int i=0; i<n; i++){
		ret = min(ret,f(health-damage[i])+cost[i]);
	}
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int h;
	cin>>h>>n;
	for(int i=0; i<n; i++) cin>>damage[i]>>cost[i];
	cout<<f(h);
}