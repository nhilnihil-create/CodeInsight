#include <iostream>
#include <vector>
#include <map>
int main()
{
	int N;
	int64_t K;
	std::cin >> N >> K;
	std::vector<int> A;
	for (int i = 0; i < N; ++i) {
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	int pos = 1;
	std::map<int, int64_t> hist;
	hist.insert(std::map<int, int64_t>::value_type(1,-1));
	int64_t count = K;
	for (int64_t i = 0; i < count; ++i) {
		pos = A[pos - 1];
		auto itr = hist.find(pos);
		if (itr == hist.end()) {
			hist.insert(std::map<int, int64_t>::value_type(pos, i));
		}
		else {
			int64_t interval = (i - itr->second);
			i += (count - 1 - i) / interval * interval;
		}
	}
	std::cout << pos << std::endl;
	return 0;
}