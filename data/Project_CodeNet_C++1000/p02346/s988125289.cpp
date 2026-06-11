#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const int INF = (1 << 30) - 1;
const ll INF64 = ((ll)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

struct SegmentTree {
private:
	int n;
	vector<int> node;
public:
	SegmentTree(vector<int> vec) {
		n = 1;
		while (n < vec.size()) {
			n *= 2;
		}

		node.resize(2 * n - 1);

		for (int i = 0; i < vec.size(); i++) {
			node[n + i - 1] = vec[i];
		}

		for (int i = n - 2; i >= 0; i--) {
			node[i] = node[2 * i + 1] + node[2 * i + 2];
		}
	}

	void add(int x, int y) {
		x += (n - 1);

		node[x] += y;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = node[2 * x + 1] + node[2 * x + 2];
		}
	}

	int getSum(int x, int y, int now = 0, int l = 0, int r = -1) {
		if (r < 0) {
			r = n;
		}

		if (r <= x || y <= l) {
			return 0;
		}

		if (x <= l && r <= y) {
			return node[now];
		}

		return getSum(x, y, 2 * now + 1, l, (l + r) / 2)
			+ getSum(x, y, 2 * now + 2, (l + r) / 2, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	SegmentTree seg(vector<int>(n, 0));
	for (int i = 0; i < q; i++) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) {
			seg.add(x - 1, y);
		} else {
			cout << seg.getSum(x - 1, y) << endl;
		}
	}
	return 0;
}

