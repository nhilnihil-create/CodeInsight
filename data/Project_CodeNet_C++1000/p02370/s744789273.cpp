#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;
typedef pair<int,int> PII;
typedef long long LL;

#define d(x)  cout<<#x<<" = "<<(x)<<endl;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define EMP empty()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c,n) sort(c,c+n)
#define VSORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define DFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define DREP(i,n) DFOR(i,n,0)
#define INF 1000000000

const double EPS = 1e-10;
const double PI  = acos(-1.0);
////////////////////////////////////////////////
int n,m;
bool V[10000];
int indeg[10000];
VI G[10000];
LI out;

void bfs(int s)
{
	queue<int> Q;
	Q.push(s);
	V[s]=true;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		out.PB(u);
		
		REP(i,SZ(G[u]))
		{
			int v=G[u][i];
			indeg[v]--;
			if(indeg[v]==0&&!V[v])
			{
				V[v]=true;
				Q.push(v);
			}
		}
	}
}

void topologicalS()
{
	REP(u,n)
	{
		if(!indeg[u]&&!V[u])
		{
			bfs(u);
		}
	}
}

int main()
{
	cin>>n>>m;
	REP(i,m)
	{
		int s,t;cin>>s>>t;
		G[s].PB(t);
		indeg[t]++;
	}
	topologicalS();
	
	for(list<int>::iterator it=out.begin();it!=out.end();it++)
	{
		cout<<*it<<endl;
	}
	
	return 0;
}