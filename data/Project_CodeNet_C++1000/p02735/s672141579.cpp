#include <iostream>
using namespace std;
int a[300][300] , b[300][300] , h , c;
int main() {
	cin >> h >> c;
	for (int i = 1 ; i <= h ; i++)
	{
		for (int e = 1 ; e <= c ; e++)
		{
			char x;
			cin >> x;
			if (x == '#')
			{
				b[i][e] = 1;
			}
			//cout <<b[i][e];
			a[0][i] = a[0][e] = a[h+1][e] = a[i][c+1] = a[i][0] = a[e][0] = 1000000;
			
		}
	}
	for (int i = 1 ; i <= h ; i++)
	{
		for (int e = 1 ; e <= c ; e++)
		{
			if (i == 1 && e == 1)
			{
				if (b[i][e] == 1)
				{
					a[i][e] = 1;
				}
				continue;
			}
			if (b[i][e] == 1)
			{
				if (b[i-1][e] == 0)
				{
					a[i][e] = a[i-1][e] + 1;
				}
				else
				{
					a[i][e] = a[i-1][e];
				}
				
				if (b[i][e-1] == 0)
				{
					a[i][e] = min(a[i][e] , a[i][e-1] + 1);
				}
				else
				{
					a[i][e] = min(a[i][e] , a[i][e-1]);
				}
			}
			else
			{
				a[i][e] = min(a[i][e-1] , a[i-1][e]);
			}
			//cout <<a[i][e];
		}
	//	cout <<'\n';
	}
	cout << a[h][c];
}