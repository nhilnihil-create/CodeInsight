#include <iostream>
#include <map>

std::map<std::pair<int, int>, int> mapa;

int findfirst(int x) {
	int tmp = 1'000'000;
	while (x / tmp == 0) tmp /= 10;

	return x/tmp;
}

int main() {
	int n;
	std::cin >> n;

	long long int ans = 0;
	long long int same = 0;
	for (int i = 1; i <= n; ++i) {

		int first = findfirst(i);
		int last = i % 10;
		std::pair<int, int> pr = std::make_pair(first, last);
		std::pair<int, int> reversepr = std::make_pair(last, first);

		if (first == last) {
			++same;
		}

		ans += mapa[reversepr];
		++mapa[pr];
	}

	std::cout << 2*ans + same;
}