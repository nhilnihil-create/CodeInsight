/*input
4 10
1 2
2 1
1 2
2 1
1 2
1 3
1 4
2 3
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
int n,m;
const int N = 200005;
int par[N], rnk[N];
int get(int x){
	if(x==par[x]) return x;
	else return par[x] = get(par[x]);
}
void union_set(int c, int d){
	c=get(c);
	d=get(d);
	if(c!=d){
		if(rnk[c]>rnk[d])swap(c, d);
		par[c]=d;
		rnk[d] += rnk[c];
	}
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) par[i]=i, rnk[i]=1;
	for(int i=0; i<m; ++i){
		int c,d;
		cin>>c>>d;
		union_set(c,d);
	}
	int ans=0;
	for(int i=1; i<=n; ++i){
		if(i==par[i]){
			ans = max(ans, rnk[i]);
		}
	}
	cout<<ans;
	return 0;	
}