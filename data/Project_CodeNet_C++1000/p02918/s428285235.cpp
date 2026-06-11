#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define maxm 
using namespace std;

int n, k; char s[maxn];
int main(){ 
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int seg = 0, first = -1;
	rep(i, 1, n) {
		char now = s[i];
		if (first == -1) first = (now == 'R') ? 1 : 0;
		while (i <= n && s[i] == now) i++; i--;
		seg++;
	}
	printf("%d\n", n - max(1, seg - 2 * k));   
	return 0;
}