#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n; char s[MAXN];
int main() {
	read(n), scanf("%s", s);
	bool found = false;
	for (int i = 0; i <= n - 1; i++)
		found |= s[i] == '2';
	if (found) {
		bool ans = false;
		for (int i = 0; i <= n - 1; i++)
			if ((i & (n - 1)) == i && s[i] == '2') ans ^= true;
		printf("%d\n", ans);
	} else {
		bool ans = false;
		for (int i = 0; i <= n - 1; i++)
			if ((i & (n - 1)) == i && s[i] == '3') ans ^= true;
		printf("%d\n", ans * 2);
	}
	return 0;
}
