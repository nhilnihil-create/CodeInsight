#include <cstdio>

int main()
{
	int a;

	char s[10];

	scanf("%d", &a);

	scanf("%s", s);

	if (a >= 3200)
	{
		printf("%s", s);
	}
	else
	{
		printf("red");
	}
}