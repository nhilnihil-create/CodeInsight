#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll x;
	cin >> x;

	ll k = x / 500;

	ll ans = (ll)k * 1000;

	x = x - (k * 500);

	k = x / 5;

	ans = ans + (k * 5);

	cout << ans << endl;
}