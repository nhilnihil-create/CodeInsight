#include <iostream>

constexpr int MAX_N = 100000;

int n, q;

int seg[MAX_N * 4];

void init(int size) {

	n = 1;

	while (n < size)
		n *= 2;
}

void add(int k, int v) {

	k += n - 1;

	seg[k] += v;

	while (k > 0) {

		k = (k - 1) / 2;

		seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];
	}
}

int getSum(int a, int b, int k, int l, int r) {

	if (r <= a || b <= l)
		return 0;
	
	if (a <= l&&r <= b)
		return seg[k];

	return getSum(a, b, k * 2 + 1, l, (l + r) / 2) + getSum(a, b, k * 2 + 2, (l + r) / 2, r);
}

int main() {

	std::cin >> n >> q;

	init(n);

	int com, x, y;

	for (int i = 0; i < q; ++i) {

		std::cin >> com >> x >> y;

		if (com == 0)
			add(x - 1, y);
		else
			std::cout << getSum(x - 1, y, 0, 0, n) << std::endl;
	}

	return 0;
}