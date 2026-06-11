#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#define N 200010
#define ll long long
#define mo ((ll)1e9+7)
//10000000000037ll
//21993833369ll
#define db double
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
bool cmp(int a, int b) {return a > b;}
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int n, m;
int fa[N], sz[N];
int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}
void Link(int u, int v) {
	int pu = Find(u), pv = Find(v);
	if (pu == pv)return;
	fa[pu] = pv;
	sz[pv] += sz[pu];
}
int main() {
	n = read(), m = read();
	rep(i, 1, n)fa[i] = i, sz[i] = 1;
	rep(i, 1, m) {
		int u = read(), v = read();
		Link(u, v);
	}
	int ans = 0;
	rep(i, 1, n)cmax(ans, sz[Find(i)]);
	printf("%d\n", ans);
	return 0;
}
