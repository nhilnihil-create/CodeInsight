#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	rep(i, n * 2 - 2) cout << x - n + 1 + i << ' ';
	cout << x + n - 1 << endl;
}