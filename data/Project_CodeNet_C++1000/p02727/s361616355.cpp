#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
const int INF = 1e9;
int m[3000];

int main() {
	int x, y, A, B, C;
	cin >> x >> y >> A >> B >> C;
	vector<int>p(A+1), q(B+1),r(C+1);
	rep(i, A)cin >> p[i];
	rep(i, B)cin >> q[i];
	rep(i, C)cin >> r[i];
	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());
	int xy = x + y;
	int pc(0), qc(0), rc(0);
	ll ans(0);
	while (xy) {
		if (pc >= x || pc>A-1)p[pc] = -1;
		if (qc >= y || qc>B-1)q[qc] = -1;
		if (rc > C - 1)r[rc] = -1;
		int k = max(p[pc], max(q[qc], r[rc]));
		//cout << k;
		if (k == p[pc])pc++;
		else if (k == q[qc])qc++;
		else rc++;
		ans += ll(k);
		xy--;
	}
	cout << ans;
	return 0;

}