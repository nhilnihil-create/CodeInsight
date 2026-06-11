#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

ll n, k;

// 5 3
// 2 3
// 1 3
//
// 10 3
// 7 3
// 4 3
// 1 3

void solve() {
	cin >> n >> k;
	cout << min(n%k, k-n%k) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

