#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#define N 1010
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
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int row[300010], column[300010];
#define pr pair<int,int>
map<pr, bool> ma;
int Mr[300010], Mc[300010];
int main() {
	int n = read(), m = read(), c = read(), mr = 0, mc = 0;

	rep(i, 1, c) {
		int x = read(), y = read();
		//printf("%d %d\n", x, y);
		ma[make_pair(x, y)] = 1;
		row[x]++, column[y]++;
		cmax(mr, row[x]), cmax(mc, column[y]);
	}
	//if (ma[po(1, 2)])puts("error");
	rep(i, 1, n)if (row[i] == mr)Mr[++Mr[0]] = i;
	rep(i, 1, m)if (column[i] == mc)Mc[++Mc[0]] = i;
	int ans = mr + mc;
	rep(i, 1, Mr[0])rep(j, 1, Mc[0]) {
		if (ma[make_pair(Mr[i], Mc[j])] == 0) {printf("%d\n", ans); return 0;}
	}
	printf("%d\n", --ans);
	return 0;
}
