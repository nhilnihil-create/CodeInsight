#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if (c - a - b > 0 && (c-a-b)*(c-a-b)-4*a*b>0) {
		cout << "Yes\n";
	}
	else cout << "No\n";
	return 0;
}