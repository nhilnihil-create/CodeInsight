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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)




int main() {
	int A, B, M,Am,Bm;
	cin >> A >> B >> M;
	vector<int> At(A);
	Am = 1000000;
	Bm = 1000000;
	for (int i = 0; i < A; i++) {
		cin >> At.at(i);
		Am = min(Am, At.at(i));
	}
	vector<int> Bt(B);
	for (int i = 0; i < B; i++) {
		cin >> Bt.at(i);
		Bm = min(Bm, Bt.at(i));
	}
	int x, y, c,sm;
	sm = 3000000;
	rep(i, M) {
		cin >> x >> y >> c;
		sm = min(sm, At.at(x - 1) + Bt.at(y - 1) - c);
	}
	sm = min(sm, Am + Bm);
	cout << sm << endl;
	

}

