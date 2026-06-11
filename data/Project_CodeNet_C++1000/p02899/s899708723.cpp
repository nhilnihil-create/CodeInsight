#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
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
#include <math.h>
using namespace std;

int main() {
	long long N;
	cin >> N;
	vector<pair<int, int>> A(N + 1);
	for (int i = 0; i < N; i++) {
		int AI;
		cin >> AI;
		A.at(i + 1).first = AI;
		A.at(i + 1).second = i + 1;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i <= N; i++) {
		if (A.at(i).first == 0) continue;
		cout << A.at(i).second << " ";
	}
	cout << endl;
}