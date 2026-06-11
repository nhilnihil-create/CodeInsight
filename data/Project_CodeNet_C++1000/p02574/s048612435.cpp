#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000000, A = 1000000;

int aa[N], kk[1 + A];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	int d = 0;
	for (int i = 0; i < n; i++)
		d = gcd(d, aa[i]);
	if (d != 1) {
		cout << "not coprime\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int x = aa[i];
		for (int a = 2; a <= x / a; a++) {
			if (x % a == 0)
				kk[a]++;
			while (x % a == 0)
				x /= a;
		}
		if (x > 1)
			kk[x]++;
	}
	for (int a = 2; a <= A; a++)
		if (kk[a] > 1) {
			cout << "setwise coprime\n";
			return 0;
		}
	cout << "pairwise coprime\n";
	return 0;
}
