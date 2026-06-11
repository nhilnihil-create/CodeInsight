#include <stdio.h>
#include <string.h>
#define N 100005
#define M 1000000007
typedef long long LL;

char s[N];
LL p3[N];

int main()
{		
	int i, l, j, t;
	LL ans = 1, tt;
	
	scanf("%s", s);
	l = strlen(s);
	for(i = 1, p3[j = 0] = 1; i < l; j = i++){
		p3[i] = p3[j] * 3 % M;
	}
	for(i = 1, j = 0, tt = 0; i < l; j = i++){
		tt += p3[j];
	}
	ans = (ans + tt * 2) % M;
	
	for(i = 1, tt = 2, j = l - 2; i < l; i++, j--){
		if(s[i] == 48) continue;
		ans += tt * p3[j] % M;
		tt <<= 1;
		if(tt >= M) tt -= M; 
	}
	ans = (ans + tt) % M;
	printf("%lld\n", ans);
			
	return 0;
}