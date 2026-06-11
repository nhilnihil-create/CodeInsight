#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			bool flag = false;
			for (int j = 2; j*j <= i; j++)
			{
				if (i % j == 0)
				{
					flag = true;
					break;
				}
			}
			if (!flag)count++;
		}

		cout << count << endl;
	}
	return 0;
}