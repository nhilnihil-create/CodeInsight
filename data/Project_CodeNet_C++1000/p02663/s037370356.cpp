#include <stdio.h>
int main(){
	int h1, m1, h2, m2, k;
	int minute, ans;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	minute = (h2- h1)*60 + (m2-m1);
	ans = minute - k;
	if (ans<=0)
	{
		printf("0");
	}else {
		printf("%d\n", ans);
	}
return 0;
}
