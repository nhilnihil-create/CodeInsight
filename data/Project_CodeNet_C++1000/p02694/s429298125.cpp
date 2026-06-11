#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll x;
	cin >> x;
	ll c = 0;
	ll ans = 100;

	while (ans < x) {
		c++;
		ans = ans + (ans / 100 );
	}

	cout << c << endl;
}