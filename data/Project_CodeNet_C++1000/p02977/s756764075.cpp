/********************************************************************************
	
	Code by a weak man who named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define ra read_alpha()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline char read_alpha() { char c = ge; while(!isalpha(c) && c != EOF) c = ge; return c; }
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

const int MAXN = 200010;

int main() {
#ifdef LOCAL
	FILE("");
#endif
	int n = ri;
	if(!(n ^ (n & -n))) return puts("No"), 0;
	printf("Yes\n%d %d\n", n + 1, 2);
	for(int i = 3; i <= n; i += 2)
		printf("1 %d\n%d %d\n1 %d\n%d %d\n", i, i, i - 1, i - 1 + n, i - 1 + n, i + n);
	if(!(n & 1)) {
		int t1 = n & -n, t2 = n - t1 + 1;
		printf("%d %d\n%d %d\n", t2, n, t1 + n, n << 1);
	}
	return 0;
}