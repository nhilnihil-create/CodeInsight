#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	string s, t;
	cin >> s >> t;
	vector<vector<int> > appearance(26);
	for (int i = 0; i < s.length(); i++) {
		appearance[s[i] - 'a'].push_back(i);
	}
	long long int start = 0;
	for (int i = 0; i < t.length(); i++) {
		int tmp = t[i] - 'a';
		if (appearance[tmp].empty()) {
			cout << -1 << endl;
			return 0;
		}
		int idxx = lower_bound(appearance[tmp].begin(), appearance[tmp].end(),
		                       start % s.length()) -
		           appearance[tmp].begin();
		int idx = appearance[tmp][idxx];
		// cout << idx << endl;
		if (idxx == appearance[tmp].size()) {
			start += s.length() - (start % s.length());
			start += appearance[tmp][0] + 1;
		} else {
			start += idx - (start % s.length()) + 1;
		}
		// cout << i << " " << start << endl;
	}
	cout << start << endl;
}