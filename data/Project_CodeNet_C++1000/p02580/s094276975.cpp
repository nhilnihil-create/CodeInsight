#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
#define IOS ios::sync_with_stdio(false)
const int maxn = 3e5 + 5;
int r[maxn], c[maxn];
map<pii, bool> mp;
vector<int> vr, vc;
void solve() {
	int h, w, m;
	scanf("%d%d%d", &h, &w, &m);
	int mr = 0, mc = 0;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		r[x]++;
		c[y]++;
		mr = max(mr, r[x]);
		mc = max(mc, c[y]);
		mp[pii(x, y)] = true;
	}
	for (int i = 1; i <= h; ++i) {
		if (mr == r[i])	vr.push_back(i); 
	}
	for (int i = 1; i <= w; ++i) {
		if (mc == c[i])	vc.push_back(i); 
	}
	for (int i : vr) {
		for (int j : vc) {
			if (!mp[pii(i, j)]) {
				//点爆方格中没有炸弹 
				printf("%d\n", mr + mc);
				return;
			}
		}
	}
	//点爆方格中面有炸弹 
	printf("%d\n", mr + mc - 1);
}
int main() {
	solve();
	return 0;
}
