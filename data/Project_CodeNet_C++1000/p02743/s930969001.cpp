#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	ll d = c - a - b;
	if (d > 0 && d * d > 4 * a * b) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}
