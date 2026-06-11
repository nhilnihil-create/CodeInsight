#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> divisor_pair(long long n) {
	vector<pair<long long, long long>> v;
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) v.emplace_back(i, n/i);
	}
	return v;
}

vector<long long> divisor(long long n) {
	vector<pair<long long, long long>> div_pair = divisor_pair(n);
	vector<long long> v(div_pair.size()*2);
	if (div_pair.back().first == div_pair.back().second) v.pop_back();
	for (int i = 0, j = v.size()-1; i < div_pair.size(); i++, j--) {
		v[i] = div_pair[i].first;
		v[j] = div_pair[i].second;
	}
	return v;
}

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	ans += divisor(n-1).size() - 1;
	vector<long long> v = divisor(n);
	for (long long k : v) {
		if (k == 1) continue;
		long long nc = n;
		while (nc % k == 0) nc /= k;
		if (nc % k == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}