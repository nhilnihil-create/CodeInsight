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


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<pair<int, int> > ans;
	int total = 0;

	if (a[0] > 0) {
		int cur = a[0];
		for(int i = 1; i < n - 1; i++) {
			ans.push_back(mkp(cur, a[i]));
			cur = cur - a[i];
		}
		ans.push_back(mkp(a[n - 1], cur));
		total = a[n - 1] - cur;
	} else if (a[n - 1] < 0) {
		int cur = a[n - 1];
		for (int i = n - 2; i >= 0; i --) {
			ans.push_back(mkp(cur, a[i]));
			cur = cur - a[i];			
		}
		total = cur;
	} else {
		int index = -1;
		int cur = a[0];
		for (int i = n - 2; i >= 1; i--) {
			if (a[i] < 0) {
				index = i;
				break;
			}
			ans.push_back(mkp(cur, a[i]));
			cur = cur - a[i];
		}

		ans.push_back(mkp(a[n - 1], cur));
		cur = a[n - 1] - cur;



		for (int i = index; i >= 1; i--) {
			ans.push_back(mkp(cur, a[i]));
			cur = cur - a[i];

		}
		total = cur;
	} 
	cout << total << endl;
	for (auto c : ans) {
		cout << c.first << " " << c.second << endl;
	}

	return 0;
}