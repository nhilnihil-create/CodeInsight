#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
char s[MAXN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] == '?') s[i] = 'D';
	printf("%s\n", s + 1);
	return 0;
}
