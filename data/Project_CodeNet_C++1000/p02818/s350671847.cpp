#include <iostream>
using namespace std;
int main() {
	long long int n, m, k;cin >> n >> m >> k;
	if (n < k) {
		long long int a = k - n;
		if (a >= m) cout << 0 << " " << 0 << endl;
		else cout << 0 << " " << m - a << endl;
	}
	else cout << n - k << " " << m << endl;
}