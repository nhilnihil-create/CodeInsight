// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int A = 100000, B = 100000, C = 100000;

int aa[A + B + C];

int main() {
	int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
	c += b += a;
	for (int i = 0; i < c; i++)
		cin >> aa[i];
	sort(aa, aa + a);
	sort(aa + a, aa + b);
	for (int i = a - 1, j = b - y - 1; i >= a - x; i--, j--)
		aa[j] = aa[i];
	sort(aa + b - x - y, aa + c);
	long long ans = 0;
	for (int i = c - 1; i >= c - x - y; i--)
		ans += aa[i];
	cout << ans << '\n';
	return 0;
}
