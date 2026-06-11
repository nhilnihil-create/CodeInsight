#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long int
#define ld long double
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define endl '\n'	
#define setbits(x) (__builtin_popcount(x))
int mod=1000000007;
int INF64=mod*mod+1;

vector<int> a;
// vector<int> sz;

int root(int i){
	while(i!=a[i]){
		a[i]=a[a[i]];
		i=a[i];
	}
	return i;
}

void join(int i, int j){
	int r1=root(i),r2=root(j);
	// if(r1==r2)	return;
	// if(sz[r2]>sz[r1])
	// 	swap(r1,r2);
	// sz[r1]+=sz[r2];
	a[r2]=r1;
}

void solve(){
	int n,m;
	cin>>n>>m;
	a.assign(n+1,1);
	// sz.assign(n+1,1);

	for(int i=1;i<=n;i++)
		a[i]=i;

	while(m--){
		int u,v;
		cin>>u>>v;
		join(u,v);
	}

	set<int> s;
	for(int i=1;i<=n;i++)
		s.insert(root(a[i]));

	cout<<(int)s.size()-1;
}

int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T;
	// cin>>T;
	T=1;
	for(int i=1;i<=T;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}