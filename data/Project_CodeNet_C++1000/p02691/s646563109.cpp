#include <iostream>
#include <unordered_map>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int main() {

	long long n; cin >> n;
	unordered_map<long long, long long> freq;
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long hi; cin >> hi;
		ans += freq[i - hi];
		freq[i + hi]++;
	}

	cout << ans;

	return 0;
}