#include<bits/stdc++.h>
#define INF 2147483640
using namespace std;
int h[100005],n,m,ans;
vector<int> G[200005];
int main()
{
	//freopen("out.txt","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> h[i];
	for(int i=0,a,b; i<m; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1; i<=n; i++)
	{
		int ok=1;
		for(auto j:G[i]) if(h[i] <= h[j]){ok=0; break;}
		if(ok) ans++;
	}
	cout << ans;
	return 0;
}