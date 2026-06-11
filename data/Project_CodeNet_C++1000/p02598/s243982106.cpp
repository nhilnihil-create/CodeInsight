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

bool search(vector<int>& a, int length, int k) {
	int count = 0;
	for(int cur : a) {
		if (cur > length) {
			count += (cur - 1) / length;
			if (count > k) return false;
		}
	}
	return  true;
}

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n);

	rep(i, n) {
		cin >> a[i];
	}
	int ok = 1000000001;
	int ng = 0;

	while(abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (search(a, mid, k)) {
			ok = mid;
		} else {
			ng = mid;
		}
		//cout << "ok:" << ok << " ng:" << ng << endl;
	}
	cout << ok << endl;


	return 0;
}
