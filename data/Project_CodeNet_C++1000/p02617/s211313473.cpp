#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define mn 200005
#define inf 4444444444444444444
#define mod (ll) 1000000007
#define base 31
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
#define mp make_pair

//int t, ntest;
int n, ans;
pii edge[mn];

void input(){
	cin>>n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;
		if (x>y) swap(x, y);
		edge[i]=mp(x, y);
	}
}

void solve(){
	for (int i=1; i<=n; i++) ans+=(i+1)*i/2;
	for (int i=1; i<n; i++){
		ans-=edge[i].fi*(n-edge[i].se+1);
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
//	cin>>t;
//	for (ntest=1; ntest<=t; ntest++){
		input();
		solve();
//	}
}

//By: 646487264



