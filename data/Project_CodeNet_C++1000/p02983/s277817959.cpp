#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int arr[60];
int n, p;

int main() {
	ll l, r;
	cin >> l >> r;
	if (r - l >= 2019)
		return cout << 0, 0;
	ll mini = 1e18;
	for (ll i = l; i <= r; i++) {
		for (ll j = i + 1; j <= r; j++) {
			mini = min(mini, (ll)(i * j) % 2019);
		}
	}
	cout << mini << endl;
}
