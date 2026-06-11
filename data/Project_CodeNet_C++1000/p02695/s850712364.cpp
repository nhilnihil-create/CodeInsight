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
int a[55],b[55],c[55],d[55];
int n,m,q;
int ans;
vector<int>v;
int val(vector<int>v){
	int x=0;
	for (int i=0;i<q;i++){
		if (v[b[i]]-v[a[i]]==c[i]){
			x+=d[i];
		}
	}
	re x;
}
void dfs(int dep){
	if (!dep){
		for (int i=1;i<=m;i++){
			v.pb(i);
			dfs(1);
			v.erase(v.end()-1);
		}
	}
	else if (dep==n){
		ans=max(ans,val(v));
	}
	else {
		for (int i=v[dep-1];i<=m;i++){
			v.pb(i);
			dfs(dep+1);
			v.erase(v.end()-1);
		}
	}
}
signed main()
{
	cin>>n>>m>>q;
	for (int i=0;i<q;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		a[i]--, b[i]--;
	}
	dfs(0);
	cout<<ans;
	re 0;
}
/*
3 4 3
1 3 3 100
1 2 2 10
2 3 2 10
*/
/*
4 6 10
2 4 1 86568
1 4 0 90629
2 3 0 90310
3 4 1 29211
3 4 3 78537
3 4 2 8580
1 2 1 96263
1 4 2 2156
1 2 0 94325
1 4 3 94328
*/