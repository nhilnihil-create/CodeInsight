#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

template<typename T, typename Q>
istream &operator>>(istream &is, pair<T, Q> &p) {
	return is >> p.first >> p.second;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}                                                                  

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> a(n); cin >> a;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end());
		m[a[i]]++;
	}
	long long ans = 0;
	for (auto p : m) {
		ans += p.second * (long long) (p.second - 1) / 2;
	}
	cout << ans << '\n';
}
