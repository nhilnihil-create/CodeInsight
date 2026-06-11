#include <bits/stdc++.h>
using namespace std;

int fa[200010], siz[200010], n, q;
int ufs(const int &u);

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		fa[i] = i, siz[i] = 1;
	while (q--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t)
			printf("%d\n", ufs(u) == ufs(v));
		else {
			if (siz[ufs(u)] < siz[ufs(v)])
				swap(u, v);
			siz[ufs(u)] += siz[ufs(v)],
				fa[ufs(v)] = ufs(u);
		}
	}
	return 0;
}

int ufs(const int &u) {
	return fa[u] == fa[fa[u]] ? fa[u] : fa[u] = ufs(fa[u]);
}

