#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include <assert.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
#include <limits>
#include <numeric>
#include<string.h>
#include<set>
#include <climits>
using namespace std;
typedef unsigned long long ull;
#define ll long long int
static const double PI = 3.141592653589793;
const ll INF = 100000000000000;
ll mod = 1000000007;
//typedef vector<int> V;
//typedef vector<V> VV;
//typedef vector<VV> VVV;

ll MOD = 1000000007;

ll fact[3000], invs[3000];

//MOD使ってる

ll pow(ll x, ll n, ll mod) { //x^n 計算量O(logn)
	ll ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x%mod;
		}
		x = x * x%mod; //一周する度にx, x^2, x^4, x^8となる
		n >>= 1; //桁をずらす n = n >> 1
	}
	return ans % mod;
}

ll combination(ll n, ll r) {
	return ((fact[n] * invs[r] % MOD) * invs[n - r]) % MOD;
}
void make_c(ll n) {
	fact[1] = 1, invs[1] = 1, invs[0] = 1;
	for (int i = 2; i < n; i++) {
		fact[i] = fact[i - 1] * i%MOD;
		invs[i] = pow(fact[i], MOD - 2, MOD);
	}
}


int main() {
	ll n, k;
	make_c(3000);
	cin >> n >> k;
	cout << n-k+1 << endl;
	for (ll i = 2; i <= k; i++) {
		if ((n - k - i + 1) < 0) {
			cout << 0 << endl;
		}
		else {
			cout<<(combination(k - 1, i - 1)*combination(n-k+1,i)) % MOD << endl;;
		}
	}

}
