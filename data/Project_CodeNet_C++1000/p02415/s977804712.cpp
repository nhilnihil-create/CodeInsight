#include<cctype>
#include<cstdio>

using namespace std;

int main()
{
	char a;
	while (1)
	{
		a = getchar();
		if (islower(a))
		{
			printf("%c", toupper(a));
		}
		else
		{
			printf("%c", tolower(a));
		}
		if (a == '\n') break;
	}
	return 0;
}