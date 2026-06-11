#include<bits/stdc++.h>
using namespace std;
int n,m;
int INF = 2000000000;
int cost[1005];
int open[1005];
int dp[1005][1<<12];
int all_opened;

int calculate(int a,int b){
	for(int i=0; i<n; i++){
		if((1<<i)&a && (1<<i)&b) a-=(1<<i);
	}
	return a;
}
int f(int key,int opened){
	int&ret = dp[key][opened];
	if(~ret) return ret;
	ret = INF;
	int new_opened = calculate(opened,open[key]);
	if(new_opened == 0) ret = cost[key];
	if(key==m) return ret;
	
	ret = min(ret,f(key+1,opened)); //이번 키를 안쓰고 다음 키부터 고려하는 경우  
	if(f(key+1,new_opened)!=INF && new_opened) ret = min(ret,f(key+1,new_opened)+cost[key]); //이번 키를 사용한 경우  
	return ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	all_opened = (1<<n)-1;
	
	for(int i=1; i<=m; i++){
		int c,o;
		cin>>c>>o;
		cost[i] = c;
		int bit = 0;
		while(o--){
			int num;
			cin>>num;
			num--;
			bit |= (1<<num);
		}
		open[i] = bit;
	}
	int mincost = f(1,all_opened);
	if(mincost==INF) cout<<-1;
	else cout<<mincost;
}