#include<bits/stdc++.h>
using namespace std;
int INF = 100000000;
int book[15][15];
int cost[15];
int main(){
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0; i<n; i++){
		cin>>cost[i];
		for(int j=0; j<m; j++) cin>>book[i][j];
	}
	int mincost = INF;
	for(int state =  1; state<(1<<n); state++){
		int skill[m]={0};
		int price = 0;
		for(int j=0; j<n; j++){
			if(state&(1<<j)){
				for(int k=0; k<m; k++) skill[k]+=book[j][k];
				price+=cost[j];
			}
		}
		bool possible = true;
		for(int j=0; j<m; j++){
			if(skill[j]<x) possible = false;
		}
		if(possible) mincost = min(mincost,price);
	}
	if(mincost==INF) cout<<-1;
	else cout<<mincost;
}