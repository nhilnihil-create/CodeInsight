#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, A, B, C, D;
int p[maxn], t;
char s[maxn];

bool check() {
	int pos = 1, l, r;
	while(p[pos] < A) ++pos;
	while(p[pos] < C) {
		if(p[pos] - 1 == p[pos - 1]) return 0;
		++pos;
	}
	pos = 1;
	while(p[pos] < B) ++pos;
	l = pos - 1;
	while(p[pos] < D) {
		if(p[pos] - 1 == p[pos - 1]) return 0;
		++pos;
	}
	r = pos;
	if(C > D) {
		if(p[l + 1] - p[l] > 3 && p[l + 1] - B > 1) return 1;
		if(p[r] - p[r - 1] > 3 && D - p[r - 1] > 1) return 1;
		for (int i = l + 2; i < r; ++i) if(p[i] - p[i - 1] > 3) return 1;
		return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	scanf("%s", s + 1);
	++t;
	for (int i = 1; i <= n; ++i) if(s[i] == '#') p[++t] = i;
	p[++t] = n + 1;
	if(check()) printf("Yes\n");
	else printf("No\n");
	return 0;
}