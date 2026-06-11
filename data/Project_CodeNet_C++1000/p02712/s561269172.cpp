#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long MOD = 1'000'000'007;

int main() {
	long n; cin >> n;
	long ans = 0;
	for (long i = 1; i <= n; i++) {
		if (i % 3 && i % 5) {
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
