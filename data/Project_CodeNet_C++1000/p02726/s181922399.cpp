#include<bits/stdc++.h>
using namespace std;
int dist[2005];
int main(){
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int d = min(j-i,1+abs(i-x)+abs(j-y));
			dist[d]++;
		}
	}
	for(int i=1; i<n; i++) cout<<dist[i]<<'\n';
}