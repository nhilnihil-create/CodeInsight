#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r=0, g=0, b=0;
	for (char c : s) {
		if (c == 'R') ++r;
		else if (c == 'G') ++g;
		else if (c == 'B') ++b;
	}
	long long ans = (long long)r * g * b;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int k = 2*j - i;
			if (k < n) {
				if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) ans--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}