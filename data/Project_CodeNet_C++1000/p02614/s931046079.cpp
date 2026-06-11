#include <iostream>
#include <numeric>
#include <cmath>
#include <queue>
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
	ll H, W, K,an=0;
	cin >> H >> W >> K;
	char c[7][7];
	rep(i, 7)rep(j, 7)c[i][j] = '.';
	rep(i, H) {
		string S;
		cin >> S;
		rep(j, W) {
			c[i][j] = S.at(j);
		}
	}
	for (int bith = 0; bith < (1 << H); ++bith) {
		for (int bitw = 0; bitw < (1 << W); ++bitw) {
			ll t = 0;
			for (int h = 0; h < H; ++h) {
				for (int w = 0; w < W; ++w) {
					if ((bith & (1 << h))&& (bitw & (1 << w))&&(c[h][w]=='#')) { // 列挙に i が含まれるか
						t++;
					}
				}
			}
			if (t == K)an++;

		}
	}
	cout << an << endl;
}