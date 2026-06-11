// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000, A = 26;

int dd[N + 1][A];

int main() {
	string s, t; cin >> s >> t;
	int n = s.length(), m = t.length();
	int inf = n * 2;
	fill(dd[n], dd[n] + A, inf);
	for (int i = n - 1; i >= 0; i--) {
		int a = s[i] - 'a';
		dd[n][a] = i;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int a = 0; a < A; a++)
			dd[i][a] = 1 + dd[i + 1][a];
		int a = s[i] - 'a';
		dd[i][a] = 0;
	}
	long long i = 0;
	for (int j = 0; j < m; j++) {
		int a = t[j] - 'a';
		int d = dd[i % n][a];
		if (d >= inf) {
			cout << "-1\n";
			return 0;
		}
		i += d + 1;
	}
	cout << i << '\n';
	return 0;
}
