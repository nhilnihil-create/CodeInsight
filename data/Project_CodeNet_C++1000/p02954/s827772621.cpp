#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 7;

int n, res[maxn];
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> s;
	n = sz(s);

	vi left, right;
	rep(i, 0, n) {
		if (s[i] == 'L') {
			left.push_back(i);
		} else {
			right.push_back(i);
		}
	}

	rep(i, 0, n) {
		if (s[i] == 'L') {
			auto it = lower_bound(right.begin(), right.end(), i);
			it--;
			int idx = *it;
			if ((i - idx) % 2 == 1) {
				res[idx + 1]++;
			} else {
				res[idx]++;
			}
		} else {
			auto it = lower_bound(left.begin(), left.end(), i);
			int idx = *it;
			if ((idx - i) % 2 == 1) {
				res[idx- 1]++;
			} else {
				res[idx]++;
			}
		}
	}
	rep(i, 0, n) {
		cout << res[i] << " ";
	}
	cout << endl;
}
