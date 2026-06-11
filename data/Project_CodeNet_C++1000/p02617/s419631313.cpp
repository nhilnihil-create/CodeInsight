#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;

int n;
vector <int> gl[200010];
long long c[200010];
void add(const int &it, const int &val);
long long query(const int &it);

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		gl[max(u, v)].push_back(min(u, v));
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		add(i, i);
		for (int j = 0; j < gl[i].size(); ++j)
			add(gl[i][j], -gl[i][j]);
		ans += query(i);
	}
	printf("%lld\n", ans);
	return 0;
}

void add(const int &id, const int &val) {
	for (int i = id; i <= n; i += lowbit(i))
		c[i] += val;
	return;
}

long long query(const int &id) {
	long long ret = 0;
	for (int i = id; i > 0; i -= lowbit(i))
		ret += c[i];
	return ret;
}

