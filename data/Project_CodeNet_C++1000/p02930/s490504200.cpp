#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


void rm(vi&v, int x)
{
	auto it=find(v.begin(), v.end(), x);
	v.erase(it);
}


int con(vvi&v, vvi&c, int l, int a, int b)
{
	if(v[a][b]>0 || v[b][a]>0) return 0;

	v[a][b]=v[b][a]=l;
	rm(c[a], b);
	rm(c[b], a);
	return 2;
}


void min_u(int&m, int v)
{
	if(m>v) m=v;
}


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vvi v(n+1), c(n+1);
		vi ct(n+1);

		for(auto&mv:v) mv.resize(n+1, -1);
		for(int i=1;i<=n;i++) ct[i]=i;
		for(int i=1;i<=n;i++)
		{
			c[i]=ct;
			rm(c[i], i);
		}

		int rest=n*(n-1)/2;
		for(int l=1;rest;l++)
		{
			vi t(n+1, -1);

			for(int skip=1;skip<n;skip++)
			{
				for(int a=1;a+skip<=n;a++)
				{
					int b=a+skip;
					if(v[a][b]>0) continue;

					int f=0;
					if(t[a]<0) f|=1;
					if(t[b]<0) f|=2;
					if(f==0)
					{
						if(!((t[a]^t[b])&1)) continue;
					}
					switch(f)
					{
						case 3:
							t[a]=0;
							t[b]=1;
							break;
						case 2:
							t[b]=t[a]+1;
							break;
						case 1:
							t[a]=t[b]+1;
							break;
					}
					v[a][b]=v[b][a]=l;
					rest--;
				}
			}
		}

		for(int i=1;i+1<=n;i++)
		{
			for(int j=i+1;j+1<=n;j++)
			{
				printf("%d ", v[i][j]);
			}
			printf("%d\n", v[i][n]);
		}
	}
	return 0;
}
