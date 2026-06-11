#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

vector<long long> spf(1e7 + 1, 0);

int main() {

	long long n; cin >> n;

	iota(spf.begin(), spf.begin() + n + 1, 0);

	for (long long i = 2; i * i <= n; i++) {
		for (long long j = i * i; j <= n; j += i) spf[j] = min(spf[j], i);
	}

	long long ans = 0;

	for (long long i = 1; i <= n; i++) {
		long long x = i, cnt = 1;
		while (x != 1) {
			long long pfac = spf[x], temp = 0;
			while (x % pfac == 0) x /= pfac, temp++;
			cnt *= (temp + 1);
		}
		ans += (i * cnt);
	}

	cout << ans;


	return 0;
}