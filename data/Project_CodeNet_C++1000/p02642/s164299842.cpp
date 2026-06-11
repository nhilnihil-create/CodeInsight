#include <stdio.h>
#define N 1000001

int c[N] = {0}, a[200002];
char f[N] = {0};

int read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	int x = c - 48;
	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;
	return x;
}

int main()
{		
	int n, m = 0, i, j, ans = 0, x;
		
	n = read();
	for(i = 0; i < n; i++){
		a[i] = x = read();
		if(x > m) m = x;
		c[x]++;
	}
	for(i = 1; i <= m; i++){
		if(!c[i]) continue;
		for(j = i << 1; j <= m; j += i) f[j] = 1;
	}
	for(i = 0; i < n; i++){
		x = a[i];
		if(c[x] == 1 && !f[x]) ans++;
	}
	printf("%d\n", ans);	
			
	return 0;
}