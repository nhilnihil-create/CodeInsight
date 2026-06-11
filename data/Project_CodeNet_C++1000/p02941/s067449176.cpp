#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, a[N], b[N], cnt = 0;
set< pair<int, int> > st;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b[i]);
		st.insert(make_pair(b[i], i));
		if (a[i] == b[i]) cnt ++;
	}
	long long ans = 0;
	while (st.size()) {
		pair<int, int> now = (*st.rbegin());
		int val = now.first;
		int pos = now.second;
		if (b[pos] == a[pos]) {
			st.erase(now);
			continue;
		}
		//printf("pos=%d, val=%d\n", pos,val);
		int to = a[pos];
		int lef = pos - 1; if (lef == 0) lef = n;
		int rig = pos + 1; if (rig == n + 1) rig = 1;
		//printf("to = %d , lef + rig = %d\n", to, b[lef] + b[rig]);
		if (to < b[lef] + b[rig]) {
			ans = ans + val / (b[lef] + b[rig]);
			if (b[pos] < b[lef] + b[rig]) {
				return !printf("-1\n");
			}
			b[pos] = b[pos] % (b[lef] + b[rig]);
			st.erase(now);
			st.insert(make_pair(b[pos], pos));
			if (b[pos] == 0) return !printf("-1\n");
		} else {
			if (b[pos] - a[pos] >= 0 && (b[pos]-a[pos])%(b[lef]+b[rig]) == 0) {
				ans += (b[pos]-a[pos])/(b[lef]+b[rig]);
				st.erase(now);
			} else {
				return !printf("-1\n");
			}
		}
	}
	cout << ans << endl;
}