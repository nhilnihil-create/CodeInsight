#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, zz[maxn], t, ans;
char s[maxn];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int x, y;
	for (x = 1; x <= n; x = y + 1) {
		y = x;
		while(y < n && s[y + 1] == s[y]) ++y;
		zz[++t] = y - x + 1;
	}
	//for (int i = 1; i <= t; ++i) printf("%d ", zz[i]); printf("\n");
	for (int i = 1; i <= t; ++i) {
		ans += (zz[i] / 3) * 2;
		zz[i] %= 3;
		if(zz[i] == 0) continue;
		if(zz[i] == 1) ++ans;
		else if(zz[i] == 2) {
			if(i < t) {
				ans += 2;
				--zz[i + 1];
			}
			else ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}