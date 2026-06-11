#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int x, y, a, b, c;
int p[MAX], q[MAX], r[MAX];
int v[MAX];

void solve() {
	cin >> x >> y >> a >> b >> c;
	for(int i=0; i<a; i++) cin >> p[i];
	for(int i=0; i<b; i++) cin >> q[i];
	for(int i=0; i<c; i++) cin >> r[i];
	sort(p, p+a);
	sort(q, q+b);
	sort(r, r+c);
	int u = 0;
	for(int i=0; i<x; i++) v[u++] = p[a-i-1];
	for(int i=0; i<y; i++) v[u++] = q[b-i-1];
	sort(v, v+u);
	int pos = c-1;
	for(int i=0; i<u && pos>=0; i++) {
		if(v[i] < r[pos]) {
			v[i] = r[pos];
			pos--;
		}
	}
	ll ans = 0;
	for(int i=0; i<u; i++) ans += v[i];
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

