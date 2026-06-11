#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;
	if (2 * b >= a) cout << 0 << '\n';
	else cout << a - (2 * b) << '\n';
}