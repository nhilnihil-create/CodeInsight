#include<bits/stdc++.h>
using namespace std;
vector<int>x[12000];int n,m,a,b,dist[12000],c[12000];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){cin>>a>>b;x[a].push_back(b);c[b]++;}
	queue<int>Q;for(int i=0;i<n;i++){if(c[i]==0)Q.push(i);}
	while(!Q.empty()){
		int a1=Q.front();Q.pop();
		for(int i=0;i<x[a1].size();i++){
			if(dist[x[a1][i]]<dist[a1]+1){
				dist[x[a1][i]]=dist[a1]+1;Q.push(x[a1][i]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){if(dist[j]==i)cout<<j<<endl;}
	}
	return 0;
}