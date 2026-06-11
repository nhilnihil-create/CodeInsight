#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

const int N = 100010;
const int mod = 10007;

inline int read() {
	int jg = 0, jk = getchar() - '0', f = 1;
	while(jk < 0 || jk > 9) {
	    if(jk == '-' - '0')  f = -1;
		jk = getchar() - '0';
	}
	while(jk >= 0 && jk <= 9)
		jg *= 10, jg += jk, jk = getchar() - '0';
	return jg * f;
}

int n, ans, k;
char s[N];

int main() {
	//freopen("a.txt", "r", stdin);
    n = read(), k = read();
	scanf("%s", s);
	for(int i = 1; i < n; ++i)
		if(s[i] == s[i - 1])
			ans++;
	ans += 2 * k;
	ans = min(ans, n - 1);
	printf("%d", ans);
	return 0;
}