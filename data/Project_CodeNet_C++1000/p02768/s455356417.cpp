#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;

class Lcombination {
public:
	ll PowIterative(ll a, ll b) {
		ll res = 1;
		for (; b > 0; b >>= 1, a = a * a % MOD) {
			if (b % 2 == 1) {
				res = res * a % MOD;
			}
		}
		return res;
	}
	ll Lcomb(ll n, ll k) {
		ll ans = 1;
		ans = LPerm(n, k);
		ll FactorialA = LPerm(k, k);
		FactorialA = PowIterative(FactorialA, MOD - 2);
		ans *= FactorialA;
		ans %= MOD;
		return ans;
	}
	ll LPerm(ll n, ll k) {
		ll res = 1;
		for (ll i = 0; i < k; i++) {
			res *= n - i;
			res %= MOD;
		}
		return res;
	}
};

int main() {
	Lcombination lc;
	int n, a, b; cin >> n >> a >> b;
	ll ans = lc.PowIterative(2, n) - 1;
	ans -= lc.Lcomb(n, a) + lc.Lcomb(n, b);
	while (ans < 0) ans += MOD;
	cout << ans << endl;

}