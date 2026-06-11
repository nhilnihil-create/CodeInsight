#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1000000000;
int hl[20005];
int hl2[20005];
int cost[10005];
main() {
	int h, n;
	cin>>h>>n;
	for(int i=1; i<=10000; i++){
		cost[i]=N;
	}
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		cost[a]=min(cost[a], b);
	}
	for(int i=1; i<=20000; i++){
		hl[i]=N;
		hl2[i]=N;
	}
	for(int i=1; i<=10000; i++){
		if(cost[i]==N){
			continue;
		}
		for(int j=0; j<=10000; j++){
			if(hl[j]==N){
				continue;
			}
			for(int x=1; x*i+j<=20000; x++){
				hl2[x*i+j]=min(hl2[x*i+j], hl[j]+x*cost[i]);
			}
		}
		for(int j=0; j<=20000; j++){
			hl[j]=min(hl[j], hl2[j]);
		}
	}
	int mini=N;
	for(int i=h; i<=20000; i++){
		mini=min(mini, hl[i]);
	}
	cout<<mini;
	return 0;
}