#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n+1);
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for(int i = n; i > 0; i--) {
		for(int j = i+i; j <= n; j += i) {
			a[i] ^= a[j];
		}
		if(a[i]) ans.push_back(i);
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}