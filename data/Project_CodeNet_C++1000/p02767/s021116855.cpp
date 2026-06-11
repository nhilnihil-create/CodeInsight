#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <memory>        // unique_ptr, shared_ptr, weak_ptr
#include <cstring>
#include <cmath>

using namespace std;

using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;

#define _LIBCPP_DEBUG 0
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
	int N, ans=0, min=9999999;
	cin >> N;

	int line[N];
	for (int i=0; i<N; i++) cin >> line[i];
	
	for (int p=0; p<101; p++) {
		for (int i=0; i<N; i++) {
			ans += pow(abs(line[i]-p), 2);
		}
		if (min > ans) min = ans;
		ans = 0;
	}

	cout << min << endl;
	return 0;
}
