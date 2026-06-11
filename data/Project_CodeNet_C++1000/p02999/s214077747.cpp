#include <bits/stdc++.h>
using namespace std;
#define ll long long 
//push_back
 
vector <ll int> v[100001];
ll int vis[100001];
ll int dist[100001];
 
 
void bfs(ll int src){
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;
 
	while(!q.empty()){
		int curr = q.front();
		q.pop();
 
		for(ll int child: v[curr]){
			q.push(child);
			dist[child] = dist[curr]+1;
			vis[child] = 1;
		}
	}
}
 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
 	
	int x,a;
	cin>>x>>a;

	if(x < a)
		cout<<0;
	else
		cout<<10;
	
}