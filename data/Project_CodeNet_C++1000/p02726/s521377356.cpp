#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0LL;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);

int main()
{
   int n,i,j;
   cin >> n;
   vector<int>g[n+1];
   for(i=1;i<n;i++)
   {
		g[i].pb(i+1);
		g[i+1].pb(i);
   }
  // cout << g[n][0] << endl;
   int x,y;
   cin >> x >> y;
   g[x].pb(y);
   g[y].pb(x);
	vector<int>v(n+1,0);
	
   for(i=1;i<n;i++)
   {
   	queue<int>q;
   	int s=i;
   	q.push(s);
   	bool vis[n+1];
	int dist[n+1];
   	memset(dist,0,sizeof(dist));
   	memset(vis,false,sizeof(vis));	
   	vis[s]=true;
   	while(!q.empty())
	{
		int f=q.front();
		//cout << f << endl;
		q.pop();
		for(j=0;j<(int)g[f].size();j++)
		{
			int w=g[f][j];
			//cout << w << endl;
			if(vis[w]==false)
			{
				//if(f==n && s==3)cout << " w " << dist[f] << endl;
				vis[w]=true;
				dist[w]=dist[f]+1;
				if(w>s){
					//if(dist[w]==2)cout << " s " << s << " w " << w << endl;
				v[dist[w]]++;}
				
				q.push(w);
			}
		}
	}
   }
   
   for(i=1;i<n;i++)
   {
   	cout << v[i] << endl;
   }
}
