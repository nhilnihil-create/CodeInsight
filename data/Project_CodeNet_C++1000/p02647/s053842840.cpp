#include <bits/stdc++.h>
const int N=2e5+1;
int n, k, a[N], b[N];
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=k; ++i) {
		memset(b+1, 0, n*sizeof(int));
		for(int i=1; i<=n; ++i) {
			++b[std::max(1, i-a[i])];
			if(i+a[i]<n) --b[i+a[i]+1];
		}
		for(int i=1; i<=n; ++i) b[i]+=b[i-1];
		if(!memcmp(a+1, b+1, n*sizeof(int))) break;
		memcpy(a+1, b+1, n*sizeof(int));
	}
	for(int i=1; i<=n; ++i) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}
