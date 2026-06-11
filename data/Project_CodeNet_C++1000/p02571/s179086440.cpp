#include<stdio.h>
int main(void) {
	int i, j;
	int scnt = 0;
	int tcnt = 0;
	int ans_diff;
	int diffcnt;
	char s[1001],t[1001];
	scanf("%s",s);
	scanf("%s",t);
	for (i = 0; s[i] != '\0'; i++)scnt++;
	for (i = 0; t[i] != '\0'; i++)tcnt++;
	ans_diff = tcnt;
	for (i = 0;i + tcnt<=scnt; i++) {
		for (j = 0, diffcnt = 0; j < tcnt; j++) {
			if (s[i + j] != t[j])diffcnt++;
		}
		if (diffcnt < ans_diff)ans_diff = diffcnt;
	}
		printf("%d", ans_diff);
	return 0;
}