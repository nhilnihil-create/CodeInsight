#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>
struct Monster {
	int position; long long int health;
};
int main() {
	int n, range; long long int damage; std::cin >> n >> range >> damage;
	std::vector<Monster> monsters(n); for (auto& m : monsters) std::cin >> m.position >> m.health;
	std::sort(monsters.begin(), monsters.end(), [](const Monster a, const Monster b) {return a.position < b.position; });
	std::queue<std::pair<int, int>> queue;
	long long int count = 0, sum = 0;
	for (auto m : monsters) {
		while (!queue.empty() && queue.front().first + range < m.position) {
			count -= queue.front().second;
			queue.pop();
		}
		m.health -= count * damage;
		if (m.health > 0) {
			queue.emplace(m.position + range, (m.health + damage - 1) / damage);
			count += (m.health + damage - 1) / damage;
			sum += (m.health + damage - 1) / damage;
		}
	}
	std::cout << sum << std::endl;
}