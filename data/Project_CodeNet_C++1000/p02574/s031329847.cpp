#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 3e6;

int n;
int v[MAX], s[MAX], vv[MAX];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	memset(v, 0, sizeof v);
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v[x]++;
		vv[i] = x;
	}
	
	memset(s, 0, sizeof s);
	s[0] = s[1] = 1;
	int ok=1;
	for(int i=2; i<MAX; i++) {
		if(s[i]) continue;
		int cnt = v[i];
		for(int j=2*i; j<MAX; j+=i) {
			s[j] = 1;
			cnt += v[j];
		}
		if(cnt > 1) ok = 0;
		// cout << i << endl;
	}
	// cout << "ok" << endl;
	if(ok) {
		cout << "pairwise coprime";
		return;
	}
	
	int a = vv[0];
	for(int i=1; i<n; i++) {
		a = gcd(vv[i], a);
	}

	if(a == 1) cout << "setwise coprime";
	else cout << "not coprime";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

