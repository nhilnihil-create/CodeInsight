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
ll gcd(ll(a), ll(b)) {
	ll c = a;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
ll A, B, X;
bool isOK(ll g,ll X) {
	if (g > X) return true;
	else return false;
}
ll keta(ll a) {
	ll k = 0;
	a = abs(a);
	if (a == 0)return 1;
	while (a > 0) {
		k++;
		a /= 10;
	}
	return k;
}
ll binary_search(ll key,ll A,ll B,ll X) {
	int left = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = 1000000000; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(A*mid+B*keta(mid),X)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return left;
}

int main() {
	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	ll C1 = (A1 - B1)*T1;
	ll C2 = (A2 - B2)*T2;
	if (C1 > 0) {
		C1 *= -1; C2 *= -1;
	}
	if (C1 + C2 < 0) {
		cout << 0 << endl;
	}
	else if (C1 + C2 == 0) {
		cout << "infinity" << endl;
	}
	else if (-C1 % (C1 + C2) == 0) {
		cout << 2 * (-C1 / (C1 + C2)) << endl;
	}
	else {
		cout << 2 * (-C1 / (C1 + C2))+1 << endl;
	}
}

