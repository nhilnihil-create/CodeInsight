#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, d;
	std::cin >> n >> d;
	d += d + 1;
	std::cout << (n + d - 1) / d << '\n';
}