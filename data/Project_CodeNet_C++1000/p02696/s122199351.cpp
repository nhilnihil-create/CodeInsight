#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, n;
	cin >> a >> b >> n;
	ll x = min(b-1, n);
	cout << (a * x) / b - a * (x / b);

	return 0;
}