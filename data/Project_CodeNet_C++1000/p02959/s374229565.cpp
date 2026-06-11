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





int main() {
	ll N;
	cin >> N;
	vector<ll> A(N + 1);
	vector<ll> B(N);
	rep(i, N+1) {
		cin >> A.at(i);
	}
	rep(i, N) {
		cin >> B.at(i);
	}
	ll an = 0;
	rep(i, N) {
		if (A.at(i) >= B.at(i)) {
			an += B.at(i);
			A.at(i) -= B.at(i);
			B.at(i) = 0;
		}
		else {
			an += A.at(i);
			B.at(i) -= A.at(i);
			A.at(i) = 0;
		}
		if (A.at(i + 1) >= B.at(i)) {
			an += B.at(i);
			A.at(i + 1) -= B.at(i);
			B.at(i) = 0;
		}
		else {
			an += A.at(i + 1);
			B.at(i) -= A.at(i + 1);
			A.at(i + 1) = 0;
		}
	}
	cout << an << endl;
}
