#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n = 0) :n(n), d(n + 1) {}
	void add(int i, T x = 1) {
		for (i++; i <= n; i += i & -i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i & -i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r - 1) - sum(l - 1);
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	BIT<long long> d(N);
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;
		d.add(i, num);
	}
	for (int i = 0; i < Q; ++i) {
		long long x, y, z;
		cin >> x >> y >> z;
		if (1 == x) {
			if (0 == y) {
				cout << d.sum(z - 1) << endl;
			}
			else {
				cout << d.sum(z - 1) - d.sum(y - 1) << endl;
			}
		}
		else {
			d.add(y, z);
		}
	}
	return 0;
}
