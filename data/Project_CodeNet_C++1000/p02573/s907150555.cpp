#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int n, m;
int uf[MAX], rnk[MAX];

int find(int i) {
	return uf[i] == i ? i : uf[i] = find(uf[i]);
}

void join(int a, int b) {
	int aa = find(a);
	int bb = find(b);
	if(aa == bb) return;
	uf[aa] = bb;
	rnk[bb] += rnk[aa] + 1;
}

void solve() {
	memset(rnk, 0, sizeof rnk);
	cin >> n >> m;
	for(int i=1; i<=n; i++) uf[i] = i;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		join(a, b);
	}
	int ans=0;
	for(int i=1; i<=n; i++) ans = max(ans, rnk[i]);
	cout << ans+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

