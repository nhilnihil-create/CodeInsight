#include <stdio.h>
int main() {
	int n, equal = 0;
	scanf("%d",&n);
	char str[n+1];
	scanf("%s",&str);

	for (int i = 0, j = n/2; i < n/2; i++,j++)
	{
		if (str[i] == str[j])
		{
			equal++;
		}
	}
	if (n % 2 == 1)
	{
		puts("No\n");
		return 0;
	}
	equal == n/2 ? puts("Yes\n") : puts("No\n");
	return 0;
}