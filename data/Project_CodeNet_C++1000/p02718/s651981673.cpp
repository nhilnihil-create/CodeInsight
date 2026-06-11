#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int n, m;
int v[MAX];

void solve() {
	cin >> n >> m;
	int sum = 0;
	for(int i=0; i<n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int ok = 0;
	for(int i=0; i<n; i++) {
		if(v[i] * 4 * m >= sum) ok++;
	}
	if(ok >= m) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

