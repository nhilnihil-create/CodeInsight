#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int n, m, u, v, fa[100005];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	cin >> n >> m;
	rep(i, 1, n) fa[i] = i;
	int ans = n - 1;
	while(m--) {
		scanf("%d%d", &u, &v);
		if(find(u) ^ find(v)) ans--, fa[fa[u]] = fa[v];
	}
	return !(cout << ans);
}