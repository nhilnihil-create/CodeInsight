#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
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
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}

vector<ll> fact, factinv, inv;
ll mod = 1e9 + 7;
void prenCkModp(ll n) {
	fact.resize(n + 5);
	factinv.resize(n + 5);
	inv.resize(n + 5);
	fact.at(0) = fact.at(1) = 1;
	factinv.at(0) = factinv.at(1) = 1;
	inv.at(1) = 1;
	for (ll i = 2; i < n + 5; i++) {
		fact.at(i) = (fact.at(i - 1) * i) % mod;
		inv.at(i) = mod - (inv.at(mod % i) * (mod / i)) % mod;
		factinv.at(i) = (factinv.at(i - 1) * inv.at(i)) % mod;
	}

}
ll nCk(ll n, ll k) {
	return (fact.at(n) * ((factinv.at(k) * factinv.at(n - k)) % mod)) % mod;
}


int main() {
	ll X, Y;
	cin >> X >> Y;
	if ((X + Y) % 3 != 0) {
		cout << 0 << endl; return 0;
	}
	ll N = (2 * Y - X) / 3;
	ll M = (X + Y) / 3 - N;
	if (N < 0 || M < 0) {
		cout << 0 << endl; return 0;
	}
	prenCkModp(N + M);
	cout << nCk(N + M, N) << endl;
}