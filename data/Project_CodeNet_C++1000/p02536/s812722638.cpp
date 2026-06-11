#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define EPS                         1e-9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define MOD                         1000000007
typedef long long ll;
/*For you see , each day i love you
 more.Today more than yesterday
  less than tomorrow.*/
using namespace std;

vector<vector<int> > g(100001);
int vis[100001];

void dfs(int node)
{
	vis[node] = 1;
	
	for(int i = 0;i<g[node].size();i++)
	{
		int y = g[node][i];
		
		if(vis[y]) continue;
		dfs(y);
	}	
}

int main()
{
	int n,m;cin>>n>>m;
	
	for(int i = 0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);	
	}
	
	int count = 0;
	
	for(int i = 1;i<=n;i++)
	{
		if(vis[i]) continue;
		
		count++;
		
		dfs(i);	
	}	
	
	cout<<count-1<<endl;
	
	return 0;
}