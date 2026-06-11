#include <bits/stdc++.h>

const static double	de_PI	= 3.14159265358979323846;
const static int	de_MOD	= 1000000007;
const static int	de_MAX	= 999999999;
const static int	de_MIN = -999999999;

int main(void) {

	//std::ifstream in("123.txt");	std::cin.rdbuf(in.rdbuf());

	int n = 0, ans = 0;
	std::vector<int> A;

	while (std::cin >> n) {
		A.push_back(n);
	}

	for (unsigned int x = 0; x < A.size(); x++) {
		ans = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {
						if (i + j + k + l == A[x]) {
							ans++;
						}
					}
				}
			}
		}
		std::cout << ans << std::endl;
	}

}