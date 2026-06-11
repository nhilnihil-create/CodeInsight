#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
map<P,int> mp;
vector<P> oder;

vector<int> G[100000];

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		oder.emplace_back(a,b);
	}

	queue<P> Q;

	Q.emplace(0,-1);
	vector<int> color(n);
	color[0] = 1;
	int par = -1;
	while(!Q.empty())
	{
		int now = Q.front().first;
		par = Q.front().second;
		Q.pop();
		int nc = 1;

		for(auto i :G[now])
		{
			if(color[i]>0)continue;
			if(par!=-1)if(mp[P(min(now,par),max(now,par))]==nc)nc++;
			mp[P(min(now,i),max(now,i))]=nc++;
			color[i] = 1;
			Q.emplace(i,now);
		}
	}
	int mx = 0;
	for(auto p:oder) mx = max(mp[p],mx);
	cout<<mx<<endl;
	for(auto p:oder)
	{
		cout<<mp[p]<<endl;
	}
	
}
