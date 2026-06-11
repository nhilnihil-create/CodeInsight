#include<cstdio>

int main()
{
	int n; scanf("%d", &n);
	int now = 0;
	
	for(int i = 0; i < n; i++){
		int inp; scanf("%d", &inp);
		if(inp == now + 1) now++;
	}
	if(now == 0) printf("-1\n");
	else printf("%d\n", n - now);
}