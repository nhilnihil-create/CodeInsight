#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

int N, M, Q;
std::vector<int> a;
std::vector<int> b;
std::vector<int> c;
std::vector<int> d;
int max_sum = 0;

void calc(std::vector<int>& A, int index) {
	if (index == A.size()) {
		int sum = 0;
		for (int i = 0; i < Q; ++i) {
			if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
				sum += d[i];
			}
		}
		if (sum > max_sum) {
			max_sum = sum;
		}
	}
	else {
		for (int i = index ? A[index - 1] : 1; i <= M; ++i) {
			A[index] = i;
			calc(A, index + 1);
		}
	}
}

int main()
{
	std::cin >> N >> M >> Q;
	for (int i = 0; i < Q; ++i) {
		int _a, _b, _c, _d;
		std::cin >> _a >> _b >> _c >> _d;
		a.push_back(_a);
		b.push_back(_b);
		c.push_back(_c);
		d.push_back(_d);
	}

	std::vector<int> A(N);
	calc(A, 0);

	std::cout << max_sum << std::endl;

	return 0;
}