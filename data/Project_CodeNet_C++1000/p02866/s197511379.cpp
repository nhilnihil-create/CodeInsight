//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000
typedef long long i64;

#define M 998244353

int n;
int a[MAXN], c[MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	return 1;
}

void init() {
}

i64 solve() {
	if (a[0]!=0) return 0;
	memset(c, 0, sizeof(c));
	for (int i=0; i<n; i++)
		c[a[i]]++;
	i64 r = 1;
	if (c[0]!=1) return 0;
	//printa(c,n);
	for (int i=1; i<n; i++) {
		if (c[i]==0) {
			for (int j=i+1; j<n; j++)
				if (c[j]) return 0;
			break;
		}
		for (int j=0; j<c[i]; j++)
			r = r * c[i-1] % M;
	}
	return r;
}

void output(i64 ans) {
	printf("%lld\n", ans);
}

void cleanup() {
}

int main() {
	//precalc();
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}


