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
	int N;
	cin >> N;
	vector<int>A(N);
	int ans = 0;

	for (int i = 0; i < N; i++) {
		A.at(i)=i+1;
		if (A.at(i) % 3 != 0 && A.at(i) % 5 != 0) {
			ans += A.at(i);
		}
	}
	cout << ans << endl;
	
}