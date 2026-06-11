#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
vector<int>v[100005];
int use[100005];
void dfs(int k){
	use[k]=1;
	for (int i : v[k])
		if (!use[i])
			dfs(i);
}
signed main()
{
	int n,m;
	cin>>n>>m;
	while (m--){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	int ans=-1;
	for (int i=0;i<n;i++)
		if (!use[i])
			dfs(i),ans++;
	cout<<ans;
	re 0;
}
