#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int K, a, b;
	cin >> K >> a >> b;

	cout << ((a + K - 1) / K * K <= b ? "OK" : "NG") << endl;

	return 0;
}
