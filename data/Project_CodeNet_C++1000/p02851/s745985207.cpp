#include <iostream>
#include <map>
using namespace std;

long long mod(long long a, long long m) {
	a %= m;
	return a >= 0 ? a : a+m;
}

int main() {
	long long n, k;
	cin >> n >> k;
	long long ans = 0, S[n+1], x[n+1];
	map<long long, int> mp;
	S[0] = 0, x[0] = 0;
	mp[0]++;
	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		S[i] = mod(S[i-1] + a, k);
		x[i] = mod(S[i] - i, k);
		if (i-k >= 0) mp[x[i-k]]--;
		ans += mp[x[i]];
		mp[x[i]]++;
	}
	cout << ans << endl;
	return 0;
}