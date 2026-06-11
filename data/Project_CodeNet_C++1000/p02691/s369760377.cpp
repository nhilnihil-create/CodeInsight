#include <iostream>
#include <map>

using ll = long long int;

int main() {
	int n;
	std::cin >> n;

	ll a[200010];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::map<int, int> mapa1;
	std::map<int, int> mapa2;
	for (int i = 0; i < n; ++i) {
		++mapa1[(i+1) - a[i]];
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += mapa1[(i+1) + a[i]];
	}

	std::cout << ans;
}