#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)
#define dump3(x, y, z) (cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", "<< z << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 1000000

int main(void)
{
	int e;
	vector<pii> vs;
	for (int y = 0;; y++) {
		int k = y*y;
		if (k > MAX) break;
		for (int z = 0;; z++) {
			int l = z*z*z;
			if (k+l > MAX) break;
			vs.push_back(pii(k+l, y+z));
		}
	}
	sort(ALL(vs));

	while (cin >> e, e) {
		int ans = (1<<29);
		rep(i, vs.size()) {
			int x = e-vs[i].first;
			if (x < 0) continue;
			ans = min(ans, x+vs[i].second);
		}
		cout << ans << endl;
	}
	return 0;
}