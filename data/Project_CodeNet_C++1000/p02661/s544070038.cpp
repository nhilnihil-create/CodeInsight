// practice with Dukkha, coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int aa[N], bb[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa[i] >> bb[i];
	sort(aa, aa + n);
	sort(bb, bb + n);
	int a, b;
	if (n % 2) {
		a = aa[n / 2];
		b = bb[n / 2];
	} else {
		a = aa[n / 2 - 1] + aa[n / 2];
		b = bb[n / 2 - 1] + bb[n / 2];
	}
	cout << b - a + 1 << '\n';
	return 0;
}
