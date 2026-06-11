#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void normalize(char* str)
{
	char res[] = "0m0c0x0i";
	char tmp = 1;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]))
		{
			tmp = str[i];
		}
		else
		{
			if (tmp == 1)	tmp = '1';
			switch(str[i])
			{
			case 'm':
				res[0] = tmp;
				break;
			case 'c':
				res[2] = tmp;
				break;
			case 'x':
				res[4] = tmp;
				break;
			case 'i':
				res[6] = tmp;
				break;
			}
			tmp = 1;
		}
	}
	for (int i = 0; i < 8; i += 2)
	{
		res[i] -= '0';
	}
	memcpy(str, res, sizeof(char) * 9);
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char str1[16], str2[16];
		scanf("%s %s", str1, str2);
		normalize(str1);
		normalize(str2);
		char str[] = "0m0c0x0i";
		for (int j = 0; j < 8; j += 2)
		{
			str[j] = str1[j] + str2[j];
		}
		for (int j = 6; j >= 0; j -= 2)
		{
			if (j != 0)
				str[j-2] += str[j] / 10;
			str[j] = str[j] % 10;
			str[j] += '0';
		}
		for (int j = 0; j < 8; j++)
		{
			if (str[j] == '0') {j++;continue;}
			if (str[j] == '1') continue;
			putchar(str[j]);
		}
		putchar('\n');
	}
	
	return 0;
}