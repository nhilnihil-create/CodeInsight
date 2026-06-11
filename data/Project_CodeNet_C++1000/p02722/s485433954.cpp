#include <bits/stdc++.h>

using namespace std;

long long n;
set<long long> se;

int main() {
	scanf("%lld", &n);
	se.insert(1), se.insert(n);
	for(int i = 2; 1LL * i * i <= n; ++i) {
		if(n % i) continue;
		long long d = i, temp = n / d;
		while(temp % d == 0) temp /= d;
		if(temp % d == 1) se.insert(d);
		d = n / i, temp = i;
		while(temp % d == 0) temp /= d;
		if(temp % d == 1) se.insert(d);
	}
	--n;
	for(int i = 1; 1LL * i * i <= n; ++i) {
		if(n % i) continue;
		se.insert(i), se.insert(n / i);
	} se.erase(1);
	printf("%d\n", int(se.size()));
	return 0;
}