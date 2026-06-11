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
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> cur_v(n,0);




	rep (i, n) {
		cin >> cur_v[i];
	}

	rep(i, k) {
		vector<int> next_v(n,0);
		vector<int> imos(n, 0);
		rep(j, n) {
			int l = j - cur_v[j];
			int r = j + cur_v[j] + 1;
			if (l < 0) {
				l = 0;
			}
			imos[l]++;
			if (r < n) {
				imos[r]--;
			}
		}

		int cur = 0;
		rep(j,n) {
			cur += imos[j];
			next_v[j] = cur;
		}

		if (cur_v == next_v) {
			break;
		}
		cur_v = next_v;
	}

	rep(i, n) {
		cout << cur_v[i] << " "; 
	}
	cout << endl;

	return 0;
}
