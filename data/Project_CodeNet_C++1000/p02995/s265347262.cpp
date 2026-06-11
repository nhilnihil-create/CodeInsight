#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	ll least_common_multiblier = c * d / __gcd(c, d);
	ll number_divisible_by_c_in_b = b / c;
	ll number_divisible_by_c_in_a = (a - 1) / c;


	ll number_divisible_by_d_in_b = b / d;
	ll number_divisible_by_d_in_a = (a - 1) / d;


	ll ans = (number_divisible_by_c_in_b + number_divisible_by_d_in_b
			- (b / least_common_multiblier))
			- (number_divisible_by_c_in_a + number_divisible_by_d_in_a
					- ((a - 1) / least_common_multiblier));
	cout << (b - a) - ans + 1;
}
