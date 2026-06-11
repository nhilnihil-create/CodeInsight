// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unordered_set<long long> ks;
	long long n;
	cin >> n;

	auto check = [&](long long k) {
		if(k==1) return false;
		long long pw = 1;
		while(pw>0&&pw<=n) {
			if(pw==n) return true;
			pw = pw * k;
		}
		pw = 1;
		while(pw>0&&pw<=n/(1+k)){
			if(n%pw==0&& (n/pw-1)%k==0) return true;
			pw=pw*k;
		}
		return false;
	};

	for(long long k = 1; k * k <= n; k++) {
		if(n % k != 0) continue;
		if(check(k)) ks.insert(k);
		if(check(n/k)) ks.insert(n/k);
	}
	for(long long k = 1; k * k <= n - 1; k++) {
		if( (n-1) % k != 0) continue;
		ks.insert(k);
		ks.insert((n-1)/k);
	}
	ks.erase(1);
	cout << ks.size();
	return 0;
}
