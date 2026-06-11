#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int n, m;

void solve() {
	cin >> n >> m;
	cout << n*(n-1)/2 + m*(m-1)/2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

