#include<stdio.h>

int get_count (char str[], int n)
{
	int c = 0;
//	int min = n / 2;
	int i;
	for (i = 0; i < n; i++)
	{
		if (str[i] == str[i + (n / 2)])
		{
			c++;
		}
	}
	
	return c;
}

int main()
{
	int n;
	scanf("%d", &n); // 0
	
	char str[n]; // str[0]
	scanf("%s", str);
	
	int mid = n / 2; // mid = 0
	int count = get_count(str, n);
	
	if (count == mid && n > 0 && n % 2 == 0)
	{
		puts("Yes");
	}
	else if (count != mid)
	{
		puts("No");
	}
	else if (n % 2 != 0)
	{
		puts("No");
	}
	else if (count <= 0)
	{
		puts("No");
	}
	
	return 0;
}