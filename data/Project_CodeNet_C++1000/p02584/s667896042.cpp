#include<iostream>
using namespace std;

int main() {
	long long x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	
	long long ans;
	if (x / d >= k) ans = x - k * d;
	else {
		if ((k - x / d) % 2 == 0) ans = x - x / d * d;
		else ans = d - x + x / d * d;
	}

	cout << ans << endl;
	return 0;
}