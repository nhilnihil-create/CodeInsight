#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
int main()
{
	int N, K;
	std::cin >> N >> K;
	std::set<int> have;
	for (int j = 0; j < K; ++j) {
		int d;
		std::cin >> d;
		for (int i = 0; i < d; ++i) {
			int A;
			std::cin >> A;
			have.insert(A);
		}
	}
	std::cout << N - have.size() << std::endl;
	return 0;
}