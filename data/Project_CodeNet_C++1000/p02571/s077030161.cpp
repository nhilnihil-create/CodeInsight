#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char a[1010];
char b[1010];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
	scanf("%s", a);
	scanf("%s", b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int ans = 0;
	for (int i = 0; i <= lena-lenb; i++)
	{
		int cnt = 0;
		for (int j = 0; j < lenb; j++)
		{
			if (a[i+j] == b[j]) cnt++;
		}
		ans = max(ans, cnt);
	}
	printf("%d", lenb - ans);
}