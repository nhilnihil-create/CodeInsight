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
vector<ll> a;

bool isOK(int index, int key) {
	if (a[index] > key) return true;
	else return false;
}

int binary_search(int key,ll i) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = i; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}


int main() {

	ll N,an=0;
	cin >> N;
	a.resize(N);
	rep(i, N) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	for (ll i = 1; i < N; i++) {
		for (ll j = i + 1; j < N; j++) {
			an +=i-binary_search(a.at(j) - a.at(i),ll(i));
		}
	}
	cout << an << endl;
}
