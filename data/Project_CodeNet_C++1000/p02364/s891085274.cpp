#include<iostream>
#include<utility>
#include<queue>
#include<functional>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
typedef pair<int,int> pii;

const int M = 10000;
vector<pii> a[M];
bool used[M]={};
int v,e;

main(){
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int s,t,w;
		cin>>s>>t>>w;
		a[s].push_back(pii(w,t));
		a[t].push_back(pii(w,s));
	}
	priority_queue< pii,vector<pii>,greater<pii> > que;
	que.push(pii(0,1));
	int ans=0;
	while(!que.empty())
	{
		pii now=que.top();que.pop();
		if(used[now.second])continue;
		ans+=now.first;
		used[now.second]=true;
		for(int i=0;i<a[now.second].size();i++)
		{
			que.push(a[now.second][i]);
		}
	}
	cout<<ans<<endl;
	
}