#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2つの整数の場合
long long GetLeastCommonMultiple(long long a, long long b) {
	long long m = a;
	long long n = b;
	long long temp;
	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return a / n * b;
}

ll func(ll x, ll c, ll d) {
	ll canC = x / c;
	ll canD = x / d;
	ll lcm = GetLeastCommonMultiple(c, d);
	ll canCandD = x / lcm;
	return x - canC - canD + canCandD;
}

int main() {

	ll a, b, c, d; cin >> a >> b >> c >> d;
	cout << func(b, c, d) - func(a - 1, c, d) << endl;
	return 0;
}