#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main() {
	cin>>n;
	ll u[n], v[n];
	vector <ll> point[n+1];
	for (int i=1; i<n; i++) {
		cin>>u[i]>>v[i];
		if (u[i]>v[i]) point[u[i]].push_back(v[i]);
		else point[v[i]].push_back(u[i]);
	}
	for (int i=1; i<=n; i++) {
		sort(point[i].begin(), point[i].end());
	}
	ll ans=0;
	for (int i=1; i<=n; i++) {
		ll tambah=i*(n-i+1);
		ans+=tambah;
	}
	for (int i=1; i<=n; i++) {
		ll byk=point[i].size(), kiri, kanan=n-i+1;
		for (int j=0; j<byk; j++) {
			if (j>0) kiri=point[i][j]-point[i][j-1];
			else kiri=point[i][j];
			ans-=(kiri*kanan*(byk-j));
		}
	}
	cout<<ans<<endl;
}

