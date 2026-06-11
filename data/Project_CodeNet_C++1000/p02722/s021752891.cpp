#include <iostream>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int res = 1;
	for (int i = 1; i * i <= (n - 1); i++) {
		int m = n - 1;
		if (m % i == 0) {
			if (i != 1) res++;
			if (i * i != m) res++;
		}
	}
	for (int i = 2; i * i <= n; i++) {
		int m = n;
		while (m % i == 0) m /= i;
		if (m != n && m % i == 1) res++;
	}
	 
	cout << res << '\n';
	
	return 0;
}