#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes;
void sieve() {
	int lim = 1e6+1000;
	vector<bool> mark(lim+6, true);
	for (int i=2; i*i<=lim; i++) {
		if (mark[i]) {
			for (int j=i*i; j<=lim; j+=i) {
				mark[j] = false;
			}
		}
	}
	
	for (int i=2; i<=lim; i++) {
		if (mark[i]) primes.emplace_back(i);
	}
	
}
int main() {
	sieve();
	int x;
	cin >> x;
	cout << *lower_bound(primes.begin(),primes.end(),x);
	return 0;
}
