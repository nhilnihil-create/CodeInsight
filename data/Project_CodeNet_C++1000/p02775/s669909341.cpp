// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int d = s[i] - '0';
		if (d != 5) {
			if (d > 5) {
				ans += 10 - d;
				if (i)
					s[i - 1]++;
				else
					ans++;
			} else if (d < 5)
				ans += d;
		} else {
			ans += 5;
			if (i && s[i - 1] >= '5')
				s[i - 1]++;
		}
	}
	cout << ans << '\n';
	return 0;
}
