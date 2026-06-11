#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
int main() {
	int n; std::cin >> n;
	std::vector<int> from_numbers(n), to_numbers(n); for (auto& a : from_numbers) std::cin >> a; for (auto& b : to_numbers) std::cin >> b;
	auto comparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.first < b.first; };
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> queue(comparator);
	for (auto i = 0; i < n; ++i) {
		if (to_numbers[i] != from_numbers[i]) queue.emplace(to_numbers[i], i);
	}
	long long int count = 0LL;
	while (!queue.empty()) {
		auto front = queue.top();
		if (to_numbers[front.second] > std::max({ to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n], from_numbers[front.second] })) {
			if (to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n] > from_numbers[front.second]) {
				queue.pop();
				count += to_numbers[front.second] / (to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n]);
				to_numbers[front.second] %= to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n];
				if (to_numbers[front.second] != from_numbers[front.second]) queue.emplace(to_numbers[front.second], front.second);
			}
			else if ((to_numbers[front.second] - from_numbers[front.second]) % (to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n]) == 0) {
				queue.pop();
				count += (to_numbers[front.second] - from_numbers[front.second]) / (to_numbers[(front.second + 1) % n] + to_numbers[(front.second + n - 1) % n]);
				to_numbers[front.second] = from_numbers[front.second];
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
	if (queue.empty()) std::cout << count << std::endl;
	else std::cout << -1 << std::endl;
}
