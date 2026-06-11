
#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
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
ll f(ll x, ll m) {
	return x % m;
}
ll mod = 998244353;
int main() {
	ll N;
	cin >> N;
	vector<ll> A(N, 0);
	bool ch = false;
	rep(i, N) {
		ll D;
		cin >> D;
		if (i == 0) {
			if(D!=0)ch = true;
			else A[D]++;
		}
		else {
			if (D == 0 || D >= N) {
				ch = true;
			}
			else {
				A[D]++;
			}
		}
	}
	ll an = 1;
	if (ch)cout << 0 << endl;
	else {
		for (ll i = 1; i < N; i++) {
			ll j = A[i];
			ll k = A[i - 1];
			if (j != 0 && k == 0) {
				cout << 0 << endl;
				return 0;
			}
			else {
				
				rep(p, j) {
					an *= k;
					an %= mod;
				}
				
			}
		}
		cout << an << endl;
	}
	
}