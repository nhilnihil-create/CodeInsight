#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MO=1e9+7;
const int M=1e5+5;

inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline int sub(int x,int y)
{
	x-=y;
	if(x<0) x+=MO;
	return x;
}
inline int mul(int x,int y)
{
	return (1LL*x*y)%MO;
}

int n,k;
vector<int> g[M];

int fa[M],inv[M],ifa[M];

void init()
{
	fa[0]=ifa[0]=1;
	inv[1]=fa[1]=ifa[1]=1;
    for(int i=2;i<M;i++)
    {
    	fa[i]=mul(fa[i-1],i);
    	inv[i]=mul((MO-MO/i),inv[MO%i]);
    	ifa[i]=mul(inv[i],ifa[i-1]);
    }
}

inline int A(int n,int m)
{
	if(m>n) return 0;
	if(n<0||m<0) return 0;
	//cout<<"! "<<n<<" "<<m<<endl;
	return mul(fa[n],ifa[n-m]);
}

int dfs(int u,int fa)
{
	int cnt=g[u].size()-(fa?1:0);
	int ans=A(k-1-(fa?1:0),cnt);
	//cout<<u<<" "<<ans<<endl;
	for(int v:g[u])
	{
		if(v==fa) continue;
		ans=mul(ans,dfs(v,u));
	}
	//cout<<u<<" "<<ans<<endl;
	return ans;
}

int main()
{
	init();
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf("%d\n",mul(k,dfs(1,0)));
	return 0;
}