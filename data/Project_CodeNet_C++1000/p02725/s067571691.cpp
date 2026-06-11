#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
int main()
{
	int K, N;
	std::cin >> K >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	int min_dist = K;
	for (int i = 0; i < N; ++i) {
		int	dist1 = (i==N-1)?(A[N-1]-A[0]):(K - A[i + 1] + A[i]);
		int	dist2 = (i == 0) ? (A[N - 1]-A[0]) : (K - A[i] + A[i - 1]);
		min_dist = std::min<int>(min_dist, dist1);
		min_dist = std::min<int>(min_dist, dist2);
	}
	std::cout << min_dist << std::endl;
	return 0;
}