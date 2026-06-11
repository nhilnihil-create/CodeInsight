#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i++)
#define re0(i, n) for (rint i = 0; i < (int) n; i++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
	for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
	if (f) x = -x;
}

const int N = 3e5 + 233;
int n;
int t[N];
string s;
string str[N];

int main(void) {
	read(n);
	rep (i, n) {
		cin >> str[i] >> t[i];
	}
	cin >> s;
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (str[i] == s)
			break;
		ans += t[i];
	}
	cout << ans << "\n";
}
