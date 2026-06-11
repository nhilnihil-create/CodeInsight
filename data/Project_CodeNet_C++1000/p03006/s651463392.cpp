#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a)
	{
		return parent[a]!=a?parent[a]=find(parent[a]):a;
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
};
int N;
long x[50],y[50];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>x[i]>>y[i];
	int ans=N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		long p=x[i]-x[j],q=y[i]-y[j];
		if(p==0&&q==0)continue;
		int now=N;
		UF uf(N);
		for(int k=0;k<N;k++)
		{
			for(int l=0;l<N;l++)
			{
				if(x[l]+p==x[k]&&y[l]+q==y[k]||x[l]-p==x[k]&&y[l]-q==y[k])
				{
					now-=uf.unite(l,k);
				}
			}
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
}
