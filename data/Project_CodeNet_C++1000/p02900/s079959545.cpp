#include<bits/stdc++.h>
int main() {
	long long num1, num2; std::cin >> num1 >> num2;
	long long a = num1, b = num2;
	std::map<long long, long long>mp;

	for (long long x = 2; x * x < num1; x++) {
		while (a % x == 0) {
			a /= x; mp[x] = 1;
		}
	}if (a != 1)mp[a] = 1;
	long long cnt = 0;
	for (long long x = 2; x * x < num2; x++) {
		while (b % x == 0) {
			b /= x; if (mp[x] == 1) { mp[x] = 2; cnt++; }
		}
	}if (b != 1)if (mp[b] == 1)cnt++;
	std::cout << cnt + 1;
}