#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
constexpr int R=5e3+69, INF=2e9+6969;

int qq,ile[R];
vector <int> v[R];

int main()
{
	int n,x,y;
	scanf("%d%d%d", &n, &x, &y);
	for(int i=1;i<n;++i)
	{
		v[i].pb(i+1);
		v[i+1].pb(i);
	}
	v[x].pb(y);
	v[y].pb(x);
	for(int i=1;i<=n;++i)
	{
		queue <pair<int,int>> q {};
		bitset <R> vis;
		vis.reset();
		q.push(mp(i,0));
		vis[i]=1;
		while(!q.empty())
		{
			int cur = q.front().fi;
			int d = q.front().se;
			q.pop();
			for(int  i=0;i<v[cur].size();++i)
			{
				if(!vis[v[cur][i]])
				{
					vis[v[cur][i]]=1;
					ile[d+1]++;
					q.push(mp(v[cur][i],d+1));
				}
			}
		}
	}
	for(int i=1;i<n;++i)
	{
		printf("%d\n", ile[i]/2);
	}
	return 0;
}
