#include<iostream>

const long long mod = 1e9 + 7;
long long cnt[100005], a[100005];

int main(void) {
	int n;
	std::cin >> n;	
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) ans = (ans * (3 - cnt[0])) % mod;
		else ans = (ans * (cnt[a[i]-1] - cnt[a[i]])) % mod;
		cnt[a[i]]++;
	}

	std::cout << ans % mod << '\n';
	return 0;
}
