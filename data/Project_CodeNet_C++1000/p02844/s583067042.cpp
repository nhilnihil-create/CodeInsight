#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	rep(i, 1000) {
		int t = i;
		int cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] - '0' == t % 10) {
				cnt++;
				t /= 10;
				if (cnt == 3) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}