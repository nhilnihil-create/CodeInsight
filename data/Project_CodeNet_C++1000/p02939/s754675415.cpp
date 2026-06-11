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
	string S;
	cin >> S;
	S += "0000000";
	vector<ll> g(S.size() + 5);
	g.at(0) = 0;
	g.at(1) = 1;
	if (S.at(0) == S.at(1)) {
		g.at(2) = 1;
	}
	else {
		g.at(2) = 2;
	}
	
	for (ll i = 3; i <= S.size(); i++) {
		if (S.at(i-1) == S.at(i-2)) {
			g.at(i) = g.at(i-3)+2;
		}
		else {
			g.at(i) = g.at(i - 1) + 1;
		}
		
	}
	
	cout << g.at(S.size()-7) << endl;
}
