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
#define int long long
using namespace std;
signed main() {
	int N, M;
	cin >> N >> M;
	int X = 0;

	vector<int>A(M);
	for (int i = 0; i < M; i++) {
		cin >> A.at(i);
		X += A.at(i);
	}
	if (N >= X) {
		cout << N - X << endl;
	}
	else {
		cout << -1 << endl;
	}
}