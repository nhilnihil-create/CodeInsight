#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

template <class T>
struct BIT {
	vector<T> data;
	BIT(int n) {
		data.assign(n, 0);
	}

	T sum (int i) {
		T res = 0;
		while (i > 0) {
			res += data[i];
			i -= i & -i;
		}
		return res;
	}

	void add(int i, T x) {
		while (i < data.size()) {
			data[i] += x;
			i += i & -i;
		}
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	BIT<Int> bit(N + 1);
	for (int i = 0; i < N; ++i) {
		Int a; cin >> a;
		bit.add(i + 1, a);
	}
	vector<Int> ans;
	for (int i = 0; i < Q; ++i) {
		int q, a, b;
		cin >> q >> a >> b;

		if (q) {
			ans.emplace_back(bit.sum(b) - bit.sum(a));
		} else {
			bit.add(a + 1, b);
		}
	}

	for (auto v : ans) { cout << v << "\n"; }

	return 0;
}
