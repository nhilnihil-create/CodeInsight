#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long, long>;
constexpr long MOD = 1000000007;

int main() {
	string s, t; cin >> s >> t;
	long ans = LONG_MAX;
	for (long i = 0; i < s.size() - t.size() + 1; i++) {
		long tmp = 0;
		for (long j = 0; j < t.size(); j++) {
			if (s[i + j] != t[j]) tmp++;
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
