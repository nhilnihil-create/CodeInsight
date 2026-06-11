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
	string W,H;
	cin >>  W;
	H = "Yes";
	if ((W.size() ) % 2 == 0) {
		rep(i, (W.size())/2) {
			if (W.at(i*2) != 'h' || W.at(i*2+1) != 'i') {
				H = "No";
			}
		}
	}
	else {
		H = "No";
	}
	cout << H << endl;

}

