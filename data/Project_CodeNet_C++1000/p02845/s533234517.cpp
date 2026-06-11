#include<iostream>

const long long mod = 1e9 + 7;
long long cnt[100005], a[100005], ans = 1;

int main(void) {
	int n;
	std::cin >> n;	
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	for (int i = 0; i < n; ++i) {
		ans = (ans * ((a[i] ? cnt[a[i]-1] : 3) - cnt[a[i]])) % mod;
		cnt[a[i]]++;
	}

	std::cout << ans << '\n';
	return 0;
}
