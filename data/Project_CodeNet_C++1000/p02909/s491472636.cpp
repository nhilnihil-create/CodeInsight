#include <cstdio>
#include <cstring>

char s[11];

int main(void)
{
	scanf("%s" ,&s[1]);

	if (strcmp(&s[1], "Sunny") == 0)
		printf("Cloudy");
	else if (strcmp(&s[1], "Rainy") == 0)
		printf("Sunny");
	else
		printf("Rainy");
	return 0;
}
