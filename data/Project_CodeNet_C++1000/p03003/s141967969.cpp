#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <numeric>
#include <bitset>
#include <random>
#include <tuple>
#include <initializer_list>
#include <fstream>
#include <cctype>
#include <string>
constexpr long long int MOD = 1000000007LL;
long long int search(const int s, const int t, const std::vector<int>& s_list, const std::vector<int>& t_list, std::vector<std::vector<long long int>> &memo) {
	if (s >= s_list.size() || t >= t_list.size()) return 1;
	else if (memo[s][t] >= 0) return memo[s][t];
	else if (s_list[s] == t_list[t]) return memo[s][t] = (search(s + 1, t, s_list, t_list, memo) + search(s, t + 1, s_list, t_list, memo)) % MOD;
	else return memo[s][t] = (search(s + 1, t, s_list, t_list, memo) + search(s, t + 1, s_list, t_list, memo) - search(s + 1, t + 1, s_list, t_list, memo)) % MOD;
}
int main() {
	int n, m; std::cin >> n >> m;
	std::vector<int> s_list(n), t_list(m);
	for (auto& s : s_list) std::cin >> s;
	for (auto& t : t_list) std::cin >> t;
	std::vector<std::vector<long long int>> memo(n + 1, std::vector<long long int>(m + 1, -1));
	for (auto i = 0; i <= m; ++i) {
		memo[n][i] = 1;
	}
	for (auto i = 0; i <= n; ++i) {
		memo[i][m] = 1;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s_list[i] == t_list[j]) {
				memo[i][j] = (memo[i + 1][j] + memo[i][j + 1]) % MOD;
			}
			else {
				memo[i][j] = (memo[i + 1][j] + memo[i][j + 1] - memo[i + 1][j + 1] + MOD) % MOD;
			}
		}
	}
	std::cout << memo[0][0] << std::endl;
}
