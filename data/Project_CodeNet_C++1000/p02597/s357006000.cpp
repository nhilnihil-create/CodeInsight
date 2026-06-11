#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

int n;
char str[N];
int p[N];
int s[N];

int main() {
	scanf("%d %s", &n, str + 1);

	for(int i = 1; i <= n; i++) {
		p[i] = p[i - 1];
		if(str[i] == 'W') p[i]++;
	}
	for(int i = n; i >= 1; i--) {
		s[i] = s[i + 1];
		if(str[i] == 'R') s[i]++;
	}

	int ans = min(p[n], s[1]);

	for(int i = 1; i <= n; i++) {
		ans = min(ans, max(p[i], s[i + 1]));
	}

	printf("%d\n", ans);
}
