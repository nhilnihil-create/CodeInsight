#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 2e5+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 18;
const int off = 1 << logo;
const int treesiz = off << 1;

int n;
vector< pair<int, int> > niz[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		for (int j = 0; j < x; j++) {
			int a, b;
			scanf("%d%d", &a, &b); a--;
			niz[i].push_back(make_pair(a, b));
		}
	}
	
	int sol = 0;
	int lim = (1 << n);
	for (int mask = 0; mask < lim; mask++) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (int j = 0; j < niz[i].size(); j++) {
					int tren = niz[i][j].first;
					int pc = niz[i][j].second;
					
					if ((!!(mask & (1 << tren))) != pc) flag = false;
				}
			}
		}
		
		if (flag) sol = max(sol, __builtin_popcount(mask));
	}
	printf("%d", sol);
	return 0;
}

