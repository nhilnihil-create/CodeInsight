#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll a = (A - 1) - (((A - 1) / C) + (A - 1) / D - (A - 1) / lcm(C, D));
	ll b = B - (B / C + B / D - B / lcm(C, D));
	ll ans = b - a;
	cout << ans << endl;
	return 0;
}