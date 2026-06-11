#include<bits/stdc++.h>
int main() {
	long long num; std::cin >> num;
	std::vector<long long>v(num + 1, 0);
	for (long long x = 1; x <= num; x++) {
		v[x]++;
		for (long long z = x * 2; z <= num; z += x) {
			v[z]++;
		}
	}
	long long ans = 0;
	for (long long x = 1; x <= num; x++) {
		ans += (1LL * x * v[x]);
	}

	std::cout << ans;
}
