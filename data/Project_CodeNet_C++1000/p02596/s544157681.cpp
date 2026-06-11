#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using i_i = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const ll mod = 1000000007LL;


int main() {
	ll cur, k;

	int count = 1;
	cur = 7;
	cin >> k;
	vector<bool> used(k, false);

	cur = cur % k;

	while(true) {
		if (cur == 0) {
			cout << count << endl;
			return 0;
		}
		if (used[cur]) {
			cout << -1 << endl;
			return 0;
		}
		used[cur] = true;

		cur = cur * 10 + 7;
		cur = cur % k;
		count++;
	}



	return 0;
}
