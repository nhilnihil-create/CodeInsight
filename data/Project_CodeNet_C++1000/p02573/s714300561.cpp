#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,fa[N],sum[N];

inline int Find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=Find(fa[x]);
}

inline void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x!=y)
    {
    	fa[y]=x;
		sum[x]+=sum[y];
	}
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
    	fa[i]=i;
    	sum[i]=1;
	}
        
    while(m--)
	{
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++) 
	 if(Find(i)==i) 
	  ans=max(ans,sum[i]);
    
	cout<<ans<<endl;
    
    return 0;
}
