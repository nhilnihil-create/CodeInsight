#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int a, b,i,j;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		for(i = 1;i <= a;i++)
		{
			for (j = 1; j <= b; j++)
			{
				if ((i + j) % 2 == 0)
				{
					cout << '#';
				}
				else
				{
					cout << '.';
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}