#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 1; i <= N; i++) {
		int a;
		std::cin >> a;
		A[a-1]++;
	}
	std::sort(A.begin(), A.end());

	std::vector<int> Sum(N+1);
	for (int i = 0; i < N; i++) {
		Sum[i+1] = Sum[i]+A[i];
	}

	for (int K = 1; K <= N; K++) {
		int l = 0, r = N/K+1;
		while(l+1 < r) {
			int c = (l+r)/2;
			bool ok = [&](int c) {
				int i = std::lower_bound(A.begin(), A.end(), c) - A.begin();
				int sum = c*(N-i) + Sum[i];
				return (sum >= c*K);
			}(c);
		if (ok) l = c; else r = c;
		}
		std::cout << l << std::endl;
	}
	return 0;
}
