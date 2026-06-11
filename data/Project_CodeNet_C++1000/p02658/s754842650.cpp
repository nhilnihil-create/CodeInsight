#include <stdio.h>
#define N 100001
typedef long long LL;

LL a[N];

LL read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	LL x = c - 48;
	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;
	return x;
}

int main()
{		
	int n, i;
	LL m = 1000000000000000000, ans = 1;
		
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		if(!(a[i] = read())) ans = 0;
	}
	if(!ans) puts("0");
	else{
		for(i = 0; i < n; i++){
			m /= a[i];
			if(!m){
				ans = -1;
				break;
			}
			ans *= a[i];
		}
		printf("%lld\n", ans);
	}
		
			
	return 0;
}