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
	string s;
	cin >> s;
	ll size = s.size();
	bool yes = true;
	if (size % 2 == 1)yes = false;
	else {
		for (int i = 0; i < size / 2; i++) {
			if (s[2 * i] == 'h' && s[2 * i + 1] == 'i') continue;
			else {
				yes = false;
				break;
			}
		}
	}
	if (yes)cout << "Yes" << endl;
	else cout << "No" << endl;
}