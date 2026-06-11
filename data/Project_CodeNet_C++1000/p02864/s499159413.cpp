#include <bits/stdc++.h>
#define db(x) cerr<<#x<<" = "<<x<<'\n'
#define int long long
using namespace std;

const int MAX=305;

int n,k,a[MAX],P[MAX],f[MAX][MAX][MAX];
bool mark[MAX][MAX][MAX];

int dp(int i,int k,int cur) {
	if(i==n+1)
		return 0;
	if(mark[i][k][cur])
		return f[i][k][cur];
	mark[i][k][cur]=true;
	// not change
	int rs=dp(i+1,k,a[i])+max(P[a[i]]-P[cur],0LL);
	// change
	if(k>0)
		rs=min(rs,dp(i+1,k-1,cur));
	return f[i][k][cur]=rs;
}

int32_t main() {
	//freopen("input","r",stdin);
	cin>>n>>k;
	vector<int> V;
	map<int,int> M;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		V.push_back(a[i]);
	}
	V.push_back(0);
	sort(V.begin(),V.end());
	V.resize(unique(V.begin(),V.end())-V.begin());
	for(int i=0;i<V.size();i++) {
		M[V[i]]=i;
		P[i]=V[i];
	}
	for(int i=1;i<=n;i++)
		a[i]=M[a[i]];
	cout<<dp(1,k,0);
}
