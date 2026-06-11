#include<bits/stdc++.h>
using namespace std;

int n, m, k;
char s[11][11];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++) scanf("%s", s[i]);
	
	int lim = (1<<(n+m));
	int ans = 0;
	for(int mask = 0; mask < lim; mask ++) {
		int cnt = 0;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if (s[i][j] == '#' && 
				!(mask & (1<<i)) &&
				!(mask & (1<<(n+j))))
				cnt++;
		if(cnt == k) ans++;
	}
	printf("%d\n", ans);
	
	return 0;
}