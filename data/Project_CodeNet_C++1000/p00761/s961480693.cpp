#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void toStr(int n, int L,char c[])
{
	int i = 0;
	for (i = 0; i < L; i++)
	{
		c[L - 1 - i] = n % 10 + '0';
		n /= 10;
  	}
	return;
}

int toNum(char c[])
{
	int index = 0;
	while (c[index] != '\0')
	{
		
	}
	return 0;
}

int getMax(char c[],int L)
{
	for (int i = 0; i < L - 1; i++)
	{
		for (int j = i + 1; j < L; j++)
		{
			if (c[i] < c[j])
			{
				char tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}
	return atoi(c);
}

int getMin(char c[] , int L)
{
	for (int i = 0; i < L - 1; i++)
	{
		for (int j = i + 1; j < L; j++)
		{
			if (c[i] > c[j])
			{
				char tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}
	return atoi(c);
}
int main()
{
	int a0, L;
	while (cin >> a0 >> L && (a0 != 0 || L != 0))
	{
		int iset[20 + 1] = {};
		int isetIndex = 1;
		int ansA = -1;
		int ansJ = -1;
		int ansIJ = -1;
		iset[0] = a0;
		while (isetIndex <= 20 && ansA == -1)
		{
			char str[20] = {};
			toStr(a0, L, str);
			int ma = getMax(str, L);
			int mi = getMin(str, L);
			int diff = ma - mi;
			a0 = diff;
			iset[isetIndex] = diff;
			isetIndex++;
		}

		bool flag = false;

		for (int i = 20;i > 0;i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (iset[i] == iset[j])
				{
					flag = true;
					ansJ = j;
					ansA = iset[i];
					ansIJ = i - j;
					break;
				}
			}
		}

		cout << ansJ << " " << ansA << " " << ansIJ << endl;
	}
	return 0;
}