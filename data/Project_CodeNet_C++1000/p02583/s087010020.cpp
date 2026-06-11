#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int N{}; std::cin >> N;
	std::vector<long long> L(N);
	for (auto& r : L) std::cin >> r;
	long long ans{};
	for (int i{ 0 }; i < N - 2; ++i) {
		for (int j{ i + 1 }; j < N - 1; ++j) {
			for (int k{ j + 1 }; k < N; ++k) {
				if ((L.at(i) + L.at(j)) > L.at(k)
					&& (L.at(i) + L.at(k)) > L.at(j)
					&& (L.at(j) + L.at(k)) > L.at(i)
					&& (L.at(i) != L.at(j)
						&& L.at(j) != L.at(k)
						&& L.at(i) != L.at(k))
					) ++ans;
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}