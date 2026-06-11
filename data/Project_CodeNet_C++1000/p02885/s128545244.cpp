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
#define rep(i,n) for(int i = 0;i<(int)(n);i++);
using namespace std;
using ll = long long;
const ll INF = 100100100100100;

ll two(ll a) {//何回2で割れるか　２以上は変わらないので２にする
	ll cnt = 0;
	while (true) {
		if (a % 2 == 0) {
			a /= 2;
			cnt++;
		}
		else break;
	}
	if (cnt >= 2) return 2;
	else return cnt;
}
int main() {
	ll A, B;
	cin >> A >> B;
	if (A >= 2 * B) cout << A - 2 * B << endl;
	else cout << "0" << endl;
}
