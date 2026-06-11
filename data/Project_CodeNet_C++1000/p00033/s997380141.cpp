#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t,flag;
	//freopen("C:\\Users\\国民党\\Desktop\\text.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		flag = 1;
		int a, b = -1, c = -1;
		for (int i = 1; i <= 10; i++)
		{
			cin >> a;
			if (a > b)
			{
				b = a;
			}
			else if (a > c)
			{
				c = a;
			}
			else
				flag = 0;
		}
		cout << ((flag == 1) ? "YES" : "NO" )<< endl;
	}
	return 0;
}