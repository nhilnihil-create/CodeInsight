#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long memo[2020][2020];
std::pair<long long, int> a[2020];
long long dp(int l, int r, int on) {
	if(l == r) return 0;
	long long &ans = memo[l][r];
	if(ans != -1) return ans;
	return ans = std::max(dp(l+1, r, on-1) + abs(l - a[on].second) * a[on].first, dp(l, r-1, on-1) + abs(r-1 - a[on].second) * a[on].first);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a, a + n);
	memset(memo, -1, sizeof memo);
	std::cout << dp(0, n, n-1) << '\n';
}