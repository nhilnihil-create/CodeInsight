#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)

int main() {
	int n,m; cin >> n >> m;
	vint h(n);
	vint ma(n);
	rep(i,n) {
		cin >> h[i];
		ma[i]=0;
	}
	rep(i,m) {
		int a,b; cin >> a >> b;
		ma[a-1]=max(h[b-1],ma[a-1]);
		ma[b-1]=max(h[a-1],ma[b-1]);
	}
	int ans=0;
	rep(i,n) {
		if(ma[i]<h[i]) ans++;
	}
	cout << ans << endl;
}