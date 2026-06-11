#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;

int mp[550][550];

int main () {
	#ifdef chitongz
//	freopen ("x.in", "r", stdin);
	#endif
	static int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			for (int k = 1; k <= 60; ++k) {
				int x = i >> (k - 1), y = j >> (k - 1);
				if ((x & 1) ^ (y & 1)) {
					mp[i][j] = mp[j][i] = k;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			printf ("%d  ", mp[i][j]);
		}
		puts ("");
	}
	return 0;
}