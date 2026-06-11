#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	int M;
	cin >> M;
	ll digit = 0;
	ll s = 0;
	for (int i = 0; i < M; i++) {
		ll d, c;
		cin >> d >> c;
		s += d * c;
		digit += c;
	}
	ll ans = (digit - 1) + ((s - 1) / 9);
	cout << ans << endl;
	return 0;
}