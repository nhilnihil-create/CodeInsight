#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
vector<int> G[MAX_N],G2[MAX_N*3];
queue<P> Q;
bool visit[MAX_N*3];
int d[MAX_N*3];

int main()
{
	int N,M;
	cin >> N >> M;
	rep(i,M)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
	}
	int S,T;
	cin >> S >> T;
	S--; T--;
	rep(i,N)
	{
		rep(j,G[i].size())
		{
			G2[i].push_back(N+G[i][j]);
			G2[N+i].push_back(2*N+G[i][j]);
			G2[2*N+i].push_back(G[i][j]);
		}
	}
	Q.push(P(S,0));
	while(!Q.empty())
	{
		P p = Q.front();
		Q.pop();
		if (!visit[p.first])
		{
			visit[p.first] = true;
			d[p.first] = p.second;
			rep(i,G2[p.first].size())
			{
				Q.push(P(G2[p.first][i],p.second+1));
			}
		}
	}
	if (d[T] == 0) cout << "-1" << endl;
	else cout << d[T] / 3 << endl;
	return 0;
}