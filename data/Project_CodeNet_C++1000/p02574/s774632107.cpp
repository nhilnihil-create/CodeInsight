#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#define N 1000010
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
int n;
int a[N], pri[N], cnt;
bool ispri[N], vis[N];
bool one, two;
void init() {
	mst(ispri, 1);
	rep(i, 2, (int)1e6)if (ispri[i]) {
		pri[++cnt] = i;
		for (int j = 2; i * j < N; ++j)ispri[i * j] = 0;
	}
}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
void solve(int x) {
	for (int i = 1; i <= cnt && pri[i] * 1ll * pri[i] <= x; ++i)
		if (x % pri[i] == 0) {
			if (!vis[pri[i]])vis[pri[i]] = 1;
			else {one = 0; return;}
			for (; x % pri[i] == 0; x /= pri[i]);
		}
	if (x > 1) {
		if (!vis[x])vis[x] = 1;
		else {one = 0; return;}
	}
}
int main() {
	n = read();
	init();
	one = 1, two = 1;
	int tmp;
	rep(i, 1, n) {
		a[i] = read();
		if (one)solve(a[i]);
		if (i == 1)tmp = a[1];
		else tmp = gcd(tmp, a[i]);
	}
	if (tmp != 1)two = 0;
	if (one)puts("pairwise coprime");
	else if (!one && two)puts("setwise coprime");
	else puts("not coprime");
	return 0;
}
