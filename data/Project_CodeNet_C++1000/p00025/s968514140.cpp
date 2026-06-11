#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
int main ()
{
	while (1)
	{
		int a[4], b[4];
		int H = 0, B = 0;
		for (int i = 0; i < 4; i++)
		{
			if (scanf("%d", &a[i]) == EOF)return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (scanf("%d", &b[i]) == EOF)return 0;
			if (b[i] == a[i])H++;
			for (int l = 0; l < 4; l++)
			{
				if (l == i)continue;
				if (a[l] == b[i])B++;
			}
		}
		cout << H << " " << B << endl;

	}
	return 0;
}