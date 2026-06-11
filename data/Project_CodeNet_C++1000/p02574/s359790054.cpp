/*  /$$                                     /$$
      | $$                                    | $$
  /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$
 /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$$$$$$$| $$      | $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/
| $$  | $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$
|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$
 \_______/ \_______/ \_______/ \______/  \_______/ \_______/|__//$$$$$$ /$$$$$$
                                                               |______/|______/

*/
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_map>
#define fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ln            cout << endl;
#define vi            vector<int>
#define vll           vector<long long>
#define sortl(vec)    sort(vec.begin(), vec.end());
#define sortr(vec)    sort(vec.rbegin(), vec.rend());
#define forn(i, x, n) for(long long i = x; i < n; i++)
#define revn(i, n, x) for(long long i = n; i >= x; i--)
#define in(vec)       for(auto &it : vec) cin >> it;
#define	out(vec)      for(auto &it : vec) cout << it << " "; ln
#define ll            long long
#define pb            emplace_back
#define mp            make_pair
#define um            unordered_map
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define ff            first
#define ss            second
#define pi            3.14159265359
#define o(x)          cout << x << endl;
#define all(a)        a.begin(), a.end()
#define sz(a)         (ll)a.size()
#define endl          "\n"
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

const ll Nfact = 200005;
const ll mod = 1000000007;
const ll Nsieve = 1000005;
//https://codeforces.com/blog/entry/74640?#comment-587521

vll county(1000005);
bool flag = 1;

vector<bool> is_prime(Nsieve, true);
void sieve() {
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= Nsieve; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= Nsieve; j += i)
				is_prime[j] = false;
		}
	}
}

ll bSearch(ll l, ll r, ll x, vll arr) {
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}
//For printing prime factors of a number
void primeFactors(ll n) {
	bool ok = 1;
	while (n % 2 == 0) {
		//cout << 2 << " ";
		if (ok) {
			county[2]++;
			ok ^= 1;
			if (county[2] >= 2)
				flag = 0;
		}
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i += 2) {
		ok = 1;
		while (n % i == 0) {
			//cout << i << " ";
			if (ok) {
				county[i]++;
				ok ^= 1;
				if (county[i] >= 2)
					flag = 0;
			}
			n = n / i;
		}
	}

	if (n > 2) {
		county[n]++;
		if (county[n] >= 2)
			flag = 0;
	}
}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modulo(ll a, ll b) {
	ll c = a % b;
	return (c < 0) ? c + b : c;
}

//Use these functions below only when modulus is involved
ll mul(ll x, ll y) {
	return (x * y) % mod;
}

ll inv(ll x) {
	return power(x, mod - 2, mod);
}

ll divide(ll x, ll y)
{
	return mul(x, inv(y));
}

ll fact[Nfact];
void precalc() { // Call this once in main()
	fact[0] = 1;
	for (ll i = 1; i < Nfact; i++)
		fact[i] = mul(fact[i - 1], i);
}

ll nCr(ll n, ll k) {
	if (n < k)
		return 0;
	return divide(fact[n], mul(fact[k], fact[n - k]));
}
void solve() {
	//If the problem is an interactive one then remove the endl macro.
	//[IMPORTANT] Make the indexing 0-based if required.
	//If using nCr, then call precalc()
	ll n;
	cin >> n;
	vll vec(n);
	in(vec)
	ll gcd = vec[0];
	forn(i, 1, n) {
		gcd = __gcd(vec[i], gcd);
	}

	if (gcd != 1) {
		o("not coprime")
		return ;
	}
	forn(i, 0, n) {
		primeFactors(vec[i]);
	}
	// out(county)
	/*forn(i, 2, 100005) {
		if (county[i] >= 2)
			o("setwise coprime") {
			return ;
		}
	}*/
	if (!flag) {
		o("setwise coprime")
	}
	else {
		o("pairwise coprime")
	}

}

int main() {
// in(vec) works for size-defined type vectors

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	fastio
	ll t = 1;
	while (t--) {
		solve();
	}
	CLOCK
	return 0;
}
