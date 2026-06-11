#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long ans = (n*(n+1)*(2*n+1)/6 + n*(n+1)/2) / 2;
	for (int i = 0; i < n-1; i++) {
		long long u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		ans -= u * (n-v+1);
	}
	cout << ans << endl;
	return 0;
}