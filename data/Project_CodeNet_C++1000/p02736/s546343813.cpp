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
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

char s[1000010];

inline int C(int n, int m) { return (n & m) == m; }

int main() {
#ifdef LOCAL
	FILE("");
#endif
	int n;
	scanf("%d%s", &n, s + 1);
	if(n == 1) putchar(s[1]), puts("");
	else {
		--n;
		int find1 = 0;
		for(int j = 1; j <= n; j++)
			s[j] = abs(s[j] - s[j + 1]), find1 |= s[j] == 1;
		if(!find1) for(int i = 1; i <= n; i++) s[i] >>= 1;
		find1 ^= 1;
		int t = 0;
		for(int j = 1; j <= n; j++) t ^= C(n - 1, j - 1) * (s[j] & 1);
		cout << (int(t) << find1) << endl;
	}
	return 0;
}