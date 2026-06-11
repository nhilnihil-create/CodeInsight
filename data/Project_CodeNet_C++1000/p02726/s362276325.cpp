#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 3e3;

int n, x, y;
int ans[MAX];

void solve() {
	memset(ans, 0, sizeof ans);
	cin >> n >> x >> y;
	if(x > y) swap(x, y);	
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			int d = min(j-i, abs(i-x) + 1 + abs(j-y));
			ans[d]++;
		}
	}
	for(int i=1; i<n; i++) cout << ans[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

