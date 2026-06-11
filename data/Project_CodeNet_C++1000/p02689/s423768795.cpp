#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::map<int, int> height;
	for (int i = 0; i < N; ++i) {
		int H;
		std::cin >> H;
		height.insert(std::map<int, int>::value_type(i+1,H));
	}
	std::multimap<int, int> route;
	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B;
		route.insert(std::multimap<int, int>::value_type(A,B));
		route.insert(std::multimap<int, int>::value_type(B,A));
	}
	int count = 0;
	for (int i = 0; i < N; ++i) {
		const int H = height.find(i + 1)->second;
		auto range = route.equal_range(i + 1);
		bool found = false;
		for (auto itr = range.first; itr != range.second; ++itr) {
			if (height.find(itr->second)->second >= H) {
				found = true;
				break;
			}
		}
		if (!found) {
			++count;
		}
	}
	std::cout << count << std::endl;
	return 0;
}