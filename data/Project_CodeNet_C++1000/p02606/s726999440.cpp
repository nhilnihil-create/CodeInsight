#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l, r, d;
	cin >> l >> r >> d;

	cout << (r / d) - ((l - 1) / d) << "\n";
}

int main() {
  solve();
}
