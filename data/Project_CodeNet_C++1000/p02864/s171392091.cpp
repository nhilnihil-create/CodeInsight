#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (310)
#define INF (1LL << 62)

ll mem[MAXN][MAXN][MAXN];
vector<ll> a;
vector<ll> s;
int n, k;
map<int, int> posmap;

ll diff(ll ph, ll h) {
	return max(0LL, h - ph);
}

ll solve(int pos, int used, int phind) {
	if (pos >= n) {
		return 0;
	}
	ll & ret = mem[pos][used][phind];
	if (ret >= 0) {
		return ret;
	}
	ll ph = s[phind];
	ret = diff(ph, a[pos]) + solve(pos + 1, used, posmap[a[pos]]);
	if (used < k) {
		ret = min(ret, solve(pos + 1, used + 1, posmap[ph]));
	//	for (int i = 0; i < s.size(); i++) {
	//		ll cur = diff(ph, s[i]) + solve(pos + 1, used + 1, i); 
	//		ret = min(ret, cur);
	//	}
	}
	return ret;
}

int main() {
//	freopen("input.txt", "r", stdin);
	memset(mem, -1, sizeof(mem));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	s = a;
	s.push_back(0);
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		posmap[s[i]] = i;
	}
	cout << solve(0, 0, 0);
	return 0;
}
