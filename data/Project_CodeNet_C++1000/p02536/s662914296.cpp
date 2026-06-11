#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<ctime>
#include<bitset>
//#include<unordered_map>
using namespace std;
#define ll long long
#define dd cout<<endl
const long long int inf = 1e18+7;
const int mod = 998244353;

inline ll max(ll a,ll b) { return a>b?a:b; }
inline ll min(ll a,ll b) { return a<b?a:b; }
inline ll abs1(ll a) { return a>0?a:-a; }

const int maxn=1e5+10;

int f[maxn];

int n,m;

inline void init()
{
	for(int i=0;i<=n+1;i++)
		f[i]=i;
}

int getf(int x)
{
	if(x==f[x])
		return x;
	else
	{
		f[x]=getf(f[x]);
		return f[x];
	}
}

void merge(int x,int y)
{
	x=getf(f[x]);
	y=getf(f[y]);
	if(x!=y)
		f[y]=x;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 	
 	cin>>n>>m;
 	
 	init();
 	
 	for(int i=0,x,y;i<m;i++)
 	{
 		cin>>x>>y;
 		
 		merge(x,y);
	}
	
	set<int>s;
	
	for(int i=1;i<=n;i++)
		s.insert(getf(f[i]));
	
	cout<<(int)s.size()-1<<endl;
	
 	return 0;
}