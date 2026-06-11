#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001;
const int NMAX=8;
const int mod = 1000000007;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n);
	rep(i,m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].emplace_back(v);
	}
	int S,T;
	cin>>S>>T;
	S--;T--;
	int d[n][3];
	rep(i,n)rep(j,3)d[i][j]=INF;
	queue <P> q;
	q.push(make_pair(S,0));
	while (!q.empty()){
		P now=q.front();
		q.pop();
		int node=now.first;
		int dist=now.second;
	//	cout<<node<<'n'<<dist<<'d'<<endl;

		for(int to:g[node]){
	//		cout<<to<<endl;
			int d_new=dist+1;
			int cat=d_new%3;
			if (d[to][cat]!=INF)continue;
			d[to][cat]=d_new;
			q.push(make_pair(to,d_new));
		}
	}
	int ans;
	if (d[T][0]==INF ) ans=-1;
	else ans=d[T][0]/3;
	cout<<ans;

}
