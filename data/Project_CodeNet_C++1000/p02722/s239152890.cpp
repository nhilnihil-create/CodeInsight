#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long> find_divisors(long long N) {
	vector<long long> res;
	for (int i = 1; 1LL * i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			if (1LL * i * i != N) {
				res.push_back(N / i);
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}
int main() {
	long long N;
	cin >> N;
	vector<long long> d1 = find_divisors(N);
	vector<long long> d2 = find_divisors(N - 1);
	vector<long long> d3 = d1;
	d3.insert(d3.end(), d2.begin(), d2.end());
	sort(d3.begin(), d3.end());
	d3.erase(unique(d3.begin(), d3.end()), d3.end());
	int ans = 0;
	for (long long i : d3) {
		if (i == 1) continue;
		long long x = N;
		while (x % i == 0) x /= i;
		if (x % i == 1) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}