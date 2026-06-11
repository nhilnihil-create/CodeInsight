#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <set> 
#include <queue> 
#define ll long long
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
ll n,m;
struct node{
	ll from,to;
}road[5000005];
ll num;
ll flag[5000005],first[5000005];
queue<int> q;
void add(ll u,ll v){
	road[++num].from=v;
	road[num].to=first[u];//u
	first[u]=num;
}
void bfs(ll tv,ll c){
	flag[tv]=c;
	q.push(tv);
	while(!q.empty()){
		ll tmp=q.front();
		q.pop();
		for(ll i=first[tmp];i;i=road[i].to){
			if(flag[road[i].from]==0){
				q.push(road[i].from);
				flag[road[i].from] = tmp;
			}
		}
	}
}
int main() 
{
	FAST_IO;
	cin>>n>>m;
	ll u,v;
	ll f=1;
	for(ll i=1;i<=m;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	bfs(1,1);
	for(ll i=1;i<=n;i++){
		if(flag[i]==0)f=0;
	}
	if(f==0)cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		for(ll i=2;i<=n;i++){
			cout<<flag[i]<<endl;
		}
	}
	return 0;
}