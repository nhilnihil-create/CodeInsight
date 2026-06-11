#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MOD = 2019;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	long long b[2019] = {1};
	int t = 0;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		t = mod(t + mod(x * (s[i-1]-'0')));
		b[t]++;
		x = mod(10 * x);
	}
	long long ans = 0;
	for (int i = 0; i < 2019; i++) {
		if (b[i] > 1) ans += b[i] * (b[i]-1) / 2;
	}
	cout << ans << endl;
	return 0;
}