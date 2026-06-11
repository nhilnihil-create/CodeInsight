#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if(!b)	return a;
	return gcd(b, a % b);
}

int main(void) {
	ll a, b;	cin >> a >> b;
	ll g = gcd(a, b);
	int cnt = 1;
	for(ll i = 2; i * i <= g; ++i) if(g % i == 0) {
		while(g % i == 0)	g /= i;
		++cnt;
	}
	if(g != 1)	++cnt;
	cout << cnt;
	return 0;
}