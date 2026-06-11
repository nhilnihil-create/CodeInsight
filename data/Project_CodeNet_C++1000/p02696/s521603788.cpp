#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll x = min(b-1, n);
	printf("%lld\n", ((a*x)/b) - (a * (x/b)));
	return 0;
}