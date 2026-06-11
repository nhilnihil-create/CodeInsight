
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
int main() {
	ll N;
	cin >> N;
	vector<ll> W(N);
	vector<ll> S(N);
	ll Wma = -(1e13);
	ll Sma = -(1e13);
	ll Wmi = (1e13);
	ll Smi = (1e13);

	rep(i, N) {
		ll x, y;
		cin >> x >> y;
		W.at(i) = x + y;
		S.at(i) = x - y;
		Wma = max(Wma, W.at(i));
		Sma = max(Sma, S.at(i));
		Wmi = min(Wmi, W.at(i));
		Smi = min(Smi, S.at(i));
	}
	cout << max(Wma - Wmi, Sma - Smi) << endl;
}