#include <bits/stdc++.h>
int main() {
	int a, v, b, w, t;
	scanf("%d%d%d%d%d", &a, &v, &b, &w, &t);
	puts(abs(a-b)<=1ll*t*(v-w)?"YES":"NO");
	return 0;
}