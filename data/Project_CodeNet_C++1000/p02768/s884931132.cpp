#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

long long fast_power(long long base, long long exp) {
    long long ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	long long fact1 = 1;
	for(int i = 1; i <= a; ++i)
		fact1 *= i, fact1 %= mod;
	long long fact2 = 1;
	for(int i = 1; i <= b; ++i)
		fact2 *= i, fact2 %= mod;
	long long tot = fast_power(2, n) - 1;
	long long cur1 = 1, cur2 = 1;
	for(int i = n; i >= n - a + 1; --i) 
		cur1 *= i, cur1 %= mod;
	for(int i = n; i >= n - b + 1; --i)
		cur2 *= i, cur2 %= mod;
	cur2 = cur2 * fast_power(fact2, mod - 2) % mod;
	cur1 = cur1 * fast_power(fact1, mod - 2) % mod;
	tot = (tot - cur2 - cur1) % mod;
	tot = (tot + mod) % mod;
	cout << tot;
}
