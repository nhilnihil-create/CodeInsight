#include <iostream>
#include <vector>
#include <algorithm>
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
	int n, k;
	cin >> n >> k;
	vector<int> A(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
	}
	auto v = divisor(sum);
	int ans = 1;
	for (int d : v) {
		vector<int> plus(A);
		for (int &e : plus) {
			e = e % d;
		}
		sort(plus.begin(), plus.end());
		vector<int> minus(plus);
		for (int &e : minus) {
			if (e != 0) e -= d;
		}
		for (int i = 1; i < n; i++) {
			plus[i] += plus[i-1];
		}
		for (int i = n-1; i > 0; i--) {
			minus[i-1] += minus[i];
		}
		int x = k+1;
		for (int i = 0; i < n-1; i++) {
			if (plus[i] == -minus[i+1]) {
				x = plus[i];
				break;
			}
		}
		if (x <= k) ans = d;
	}
	cout << ans << endl;
	return 0;
}