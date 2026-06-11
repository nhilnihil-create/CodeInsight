#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int OFF = (1 << 20);

int n;
ll a, b;

int main () {

	cin >> n;
	ll sol = 0;
	for (int i = 1; i <= n; i++) {
		ll tren = n-i+1;
		tren *= i;
		sol += tren;
	}
	
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		ll tren = n-b+1;
		tren *= a;
		sol -= tren;
	}
	
	cout << sol;

	return 0;
}