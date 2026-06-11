// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100001, MD = 1000000007;

int pp[N];

int main() {
	string s; cin >> s;
	int n = s.length();
	for (int p = 1, i = 0; i < n; i++, p = p * 3LL % MD)
		pp[i] = p;
	long long ans = 0, cnt = 1;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') {
			ans = (ans + cnt * pp[n - 1 - i]) % MD;
			cnt = cnt * 2 % MD;
		}
	ans = (ans + cnt) % MD;
	cout << ans << '\n';
	return 0;
}
