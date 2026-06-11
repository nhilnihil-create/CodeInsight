#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;

	ll div = N / (A + B);
	ll mod = N % (A + B);

	ll ans = div * A;
	if (mod > A) {
		ans += A;
	}
	else {
		ans += mod;
	}

	cout << ans << endl;
	return 0;
}
