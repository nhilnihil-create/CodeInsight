#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
	#define debug(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(...) 42
#endif

#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

inline string getString(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string getLine(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
typedef long long ll;

const int S=200100;
int n,m;

int root[S+5];
int siz[S+5];

void Init()
{
	for(int i=0;i<=S;i++)root[i]=i,siz[i]=1;
}

int Find_root(int x)
{
    if(root[x]==x)return x;
    return root[x]=Find_root(root[x]);
}

void Union(int u,int v)
{
    u=Find_root(u);
    v=Find_root(v);
    if(u==v)return;

    if(siz[u]>siz[v])swap(u,v);
    siz[v]+=siz[u];
    siz[u]=0;
    root[u]=v;
}

int main()
{
	while(~sf("%d %d",&n,&m))
	{
		Init();
		for(int i=0;i<m;i++)
		{
			int u,v;
			sf("%d %d",&u,&v);
			if(Find_root(u)!=Find_root(v))Union(u,v);
		}

		int mx=*max_element(siz+1,siz+1+n);
		pf("%d\n",mx);
	}
    return 0;
}

































