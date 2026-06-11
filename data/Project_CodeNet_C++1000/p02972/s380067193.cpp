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





int main() {
	ll N,an=0;
	cin >> N;
	vector<int> a(N);
	rep(i, N) {
		cin >> a.at(i);
	}
	vector<ll> B(N, 0);
	for (ll i = N; i > 0;i--) {
		ll j = i;
		ll k = 0;
		while (j <= N) {
			k += B[j - 1];
			j += i;
		}
		if (k % 2 != a[i - 1]) { 
			B[i - 1] = 1; 
			an++;
		}
		else B[i - 1] = 0;
	}
	cout << an << endl;
	rep(i, N) {
		if (B[i] == 1) {
			an--;
			cout << i + 1;
			if (an != 0) {
				cout << " ";
			}
		}
	}
}