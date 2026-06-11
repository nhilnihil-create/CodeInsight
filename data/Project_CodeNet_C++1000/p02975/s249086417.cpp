#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, a[maxn], p[maxn], d[maxn];

int main() {
	scanf("%d", &n); a[0] = -1;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if(a[n] == 0) printf("Yes\n");
	else {
		if(n % 3) printf("No\n");
		else {
			int cnt = 0;
			for (int i = 1; i <= n && cnt <= 3; ++i) {
				if(a[i] != a[i - 1]) {
					d[cnt] = i - 1;
					p[++cnt] = a[i];
				}
			}
			d[cnt] = n;
			for (int i = cnt; i; --i) d[i] -= d[i - 1];
			if(cnt == 1 || cnt > 3) printf("No\n");
			else {
				if(cnt == 2 && d[2] == d[1] * 2 && p[1] == 0) printf("Yes\n");
				else if(cnt == 3 && d[1] == d[2] && d[2] == d[3] && ((p[1] ^ p[2]) == p[3])) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}