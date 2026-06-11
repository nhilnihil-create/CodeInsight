# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
using namespace std;
using LL = long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);

std::vector<int> prime;
void MakePrime(int n) {
	prime.emplace_back(2);
	for (int i = 3; i < n; i += 2) {
		bool a = false;
		for (int j = 3; j <= std::sqrt(i); j += 2) {
			if (i%j == 0) {
				a = true;
			}
		}
		if (a == false) {
			prime.emplace_back(i);
		}
	}
}

int C;

int main() {
	int n;
	while (cin >> n&&n) {
		prime.clear();
		MakePrime(n * 2);
		C = 0;
		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] > n) {
				C++;
			}
		}
		cout << C << endl;
	}
}