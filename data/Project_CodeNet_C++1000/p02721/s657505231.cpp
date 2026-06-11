#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	vector<int> l(k), r(k);
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (d == 0 || l[d - 1] + c < i) {
				l[d] = i;
				d++;
			}
		}
		if (d == k)break;
	}
	d = k - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'o') {
			if (d == k - 1 || r[d + 1] - c > i) {
				r[d] = i;
				d--;
			}
		}
		if (d == -1)break;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (l[i] == r[i]) {
			cout << l[i] + 1 << "\n";
		}
	}
}