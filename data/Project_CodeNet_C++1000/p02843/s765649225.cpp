#include <iostream>
#include <numeric>
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}

int pch(ll H) {
	ll i = 2;
	while (i * i <= H) {
		if (H % i == 0) {
			return -1;
		}
		i++;
	}
	return H;
}



int main() {
	ll X;
	cin >> X;
	if (X >= 10500) {
		cout << 1 << endl;
		return 0;
	}
	else if ((X / 100) * 5 >= X % 100) {
		cout << 1 << endl;
		return 0;
	}
	else {
		cout << 0 << endl;
	}
	
}



