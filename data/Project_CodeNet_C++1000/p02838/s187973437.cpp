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
ll mod = 1e9 + 7;
ll A0[62];
ll A1[62];
int main() {
	ll N;
	cin >> N;
	rep(i, N) {
		ll t;
		cin >> t;
		rep(j, 62) {
			if (t % 2 == 0)A0[j]++;
			else A1[j]++;

			t /= 2;
		}
	}
	ll an=0;
	ll k = 1;
	rep(j, 62) {
		an += ((((A0[j] * A1[j])) % mod)*k)%mod;
		k *= 2;
		k %= mod;
		
	}
	cout << an % mod << endl;
}
