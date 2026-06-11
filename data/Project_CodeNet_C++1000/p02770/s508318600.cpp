#include <iostream>
using namespace std;

int d[5009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, q; cin >> k >> q;
	for (int i = 0; i < k; i++)
		cin >> d[i];
	for (int i = 0; i < q; i++) {
		int n, x, m; cin >> n >> x >> m; 
		n -= 2; x = x % m;
		long long s = 0, ts = 0;
		int c = 0, tc = 0;
		for (int j = 0; j < k; j++) {
			s += d[j] % m;
			if (d[j] % m == 0) c++;
			if (j == n % k) {
				ts = s; tc = c;
			}
		}
		s = s * (n / k) + ts + x;
		c = c * (n / k) + tc;
		cout << n + 1 - (s / m + c) << '\n';
	}
	return 0;
}
