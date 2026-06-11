#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L' && i > 0 && s[i-1] == 'L') ans++;
		if (s[i] == 'R' && i < n-1 && s[i+1] == 'R') ans++;
	}
	ans = min(ans + 2*k, n-1);
	cout << ans << endl;
	return 0;
}