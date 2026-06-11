#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[i + 1]) {
			ans++;
		}
	}
	if (ans == 0) {
		cout << 1;
	}
	else {
		cout << ans;
	}
	
}
