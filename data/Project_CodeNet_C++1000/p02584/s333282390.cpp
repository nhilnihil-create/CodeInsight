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
int main() {
	ll x, k, d;
	scanf("%lld%lld%lld", &x, &k, &d);
	if (x < 0)x *= -1ll;
	ll tmp = min(k, x / d);
	k -= tmp, x -= tmp * 1ll * d;
	if (k & 1)x -= d;
	printf("%lld\n", (ll)fabs(x));
	return 0;
}