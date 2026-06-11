#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;


int main()
{
	int n;
	cin>>n;
	
	bool adj[n+10][n+10]={};
	
	for(int i=1;i<n+1;++i){//1index
		
		int u;
		int k;
		cin>>u>>k;
		
		for(int j=1;j<k+1;++j){//1index
			int v;
			cin>>v;
			adj[i][v]=true;
		}
	}
	
	int d[n+10];
	for(int i=1;i<n+1;++i){
		d[i]=-1;
	}
	
	d[1]=0;
	
	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		
		int a=d[now];
		
		for(int j=1;j<n+1;++j){
			
			if((adj[now][j]) and (d[j]==-1)){
				d[j]=a+1;
			que.push(j);
			
			}
			
		}
	}
	
	for(int i=1;i<n+1;++i){
		cout<<i<<" "<<d[i]<<endl;
	}
	
}
