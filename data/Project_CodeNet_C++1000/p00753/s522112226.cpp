#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

//?????????: n??\???????´???°
vector<int> getPrimes(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
		if (is_prime[i]) {
			int j = i + i;
			while (j <= n) {
				is_prime[j] = false;
				j = j + i;
			}
		}
	vector<int> primes;
	rep(i, 0, n + 1)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}

signed main() {
	for (int n; cin >> n&&n;) {
		cout << getPrimes(2 * n).size() - getPrimes(n).size() << endl;
	}
	return 0;
}