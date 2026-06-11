#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long MOD = 1'000'000'007;

int main() {
	long n; string s;
	cin >> n >> s;
	long r, g, b;
	r = g = b = 0;
	for (long i = 0; i < n; i++) {
		switch (s[i]) {
			case 'R':
				r++;
				break;
			case 'G':
				g++;
				break;
			case 'B':
				b++;
				break;
		}
	}
	long ans = r * g * b;
	for (long i = 0; i < n; i++) {
		for (long j = i+1; j < n; j++) {
			long k = j + (j - i);
			if (k < n) {
				if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
					ans--;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
