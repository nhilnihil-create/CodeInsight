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

#define mod 1000000007

int n;
vector<int> cnt;
vector<int> sumcnt;

int solve(int k) {
	int l = 0, r = n / k + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int overmind = lower_bound(cnt.begin(), cnt.end(), m) - cnt.begin();
		int overmnum = n - overmind;
		if (overmnum >= k) {
			l = m;
			continue;
		}
		int restind = overmind - (k - overmnum);
		int rest = sumcnt[overmind] - sumcnt[restind];
		int need = m * (k - overmnum) - rest;
		if (sumcnt[restind] >= need) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

int main() {
	cin >> n;
	cnt = vector<int>(n, 0);
	sumcnt = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a--;
		cnt[a]++;
	}
	sort(cnt.begin(), cnt.end());
	for (int i = 1; i <= n; i++) {
		sumcnt[i] = sumcnt[i - 1] + cnt[i - 1];
	}
	for (int k = 1; k <= n; k++) {
		cout << solve(k) << endl;
	}
}