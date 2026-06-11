#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

ll n, v[MAX], a[MAX];
long long t, ans;

void solve() {
	memset(v, 0, sizeof v);
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v[x]++;
		a[i] = x;
	}
	
	t = 0ll;
       	for(int i=1; i<=n; i++) {
		t += (ll)((v[i] * (v[i]-1)) / 2);
	}
	
	for(int i=0; i<n; i++) {
		ans = (ll)(t) + 1ll - (ll)(v[a[i]]);
		cout << (ll)(ans) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

