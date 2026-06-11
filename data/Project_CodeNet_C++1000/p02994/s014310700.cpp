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

template<typename T, typename Q>
ostream &operator<<(ostream &os, pair<T, Q> p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
	os << "[";
	for (auto it = v.begin(); it != v.end(); it++)
		os << (it == v.begin() ? "" : ", ") << *it;
	return os << "]";
}

template<typename T, typename Q>
ostream &operator<<(ostream &os, map<T, Q> m) {
	os << "[";
	for (auto it = m.begin(); it != m.end(); it++) 
		os << (it == m.begin() ? "" : ", ") << *it;
	return os;
}
#define imie(...) " [" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l; cin >> n >> l;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += l + i - 1;
	}
	long long ans = 1e18;
	long long ans2;
	for (int i = 1; i <= n; i++) {
		if (ans > abs(sum - (sum - (l + i - 1)))) {
			ans = abs(sum - (sum - (l + i - 1)));
			ans2 = sum - (l + i - 1);
		}
	}
	cout << ans2 << '\n';
}
