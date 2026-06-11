#include <iostream> // cout, endl, cin
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
#include<math.h>
#define rep(i,n) for(int i = 0;i<(n);i++);
using namespace std;
using ll = long long;
const ll INF = 100100100100100;

int main() {
	ll H, W;
	cin >> H >> W;
	if (H == 1 || W == 1)cout << "1" << endl;
	else {
		if (H * W % 2 == 1) cout << H * W / 2 + 1 << endl;
		else cout << H * W / 2 << endl;
	}
}