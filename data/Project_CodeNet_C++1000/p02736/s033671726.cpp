#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 1000005;

int n, i, ex, res, tab[N];
char t[N];

int get(int x) {
	int res = 0;
	int l = 2;
	while (l <= x) {
		res += x / l;
		l *= 2;
	}
	return res;
}

bool odd(int a, int b) {
	return get(a) - get(b) - get(a - b) == 0;
}

int main() {
scanf("%d", &n);
scanf("%s", t);
for (i=0;i<n;i++) {
	tab[i] = int(t[i]) - '0' - 1;
	if (tab[i] == 1) {
		ex = 1;
		if (odd(n - 1, i)) res = 1 - res;
		//printf("%d %d\n", i, res);
	}
}

if (res) printf("1\n"); else if (ex) printf("0\n"); else {
	for (i=0;i<n;i++) if (tab[i] == 2 && odd(n - 1, i)) res = 1 - res;
	if (res) printf("2\n"); else printf("0\n");
}
return 0;
}



