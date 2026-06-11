#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 

typedef long long ll;
using namespace std;
const ll m = 1e9 + 7;

int main() {
	ll x, k, d; cin >> x >> k >> d;
	x = abs(x);
	ll temp = min(k, x / d);
	k -= temp;
	x -= temp * d;

	if (k & 1) {
		cout << d - x << endl;
	}
	else {
		cout << x << endl;
	}
    return 0;
}