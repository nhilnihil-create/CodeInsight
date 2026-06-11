#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int N; 
	std::cin >> N;
	std::vector<int> L(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
	}
	std::sort(L.begin(), L.end());

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i < j && j < k) {
					if (L[i] == L[j] || L[j] == L[k]) {
						continue;
					}
					else if (L[i] + L[j] > L[k]) {
						ans++;
					}
				}
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}