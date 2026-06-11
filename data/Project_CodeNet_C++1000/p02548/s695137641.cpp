//int he name of GOD//
#include <bits/stdc++.h>

using namespace std;

int n, g, cnt;

int main()
{
	cin >> n;
	g = sqrt(n);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(i*j < n)
			{
//				cout << i<< ' '<< j<< ' '<< (n-(i*j))<< endl;
				cnt++;
			}
			else
			{
				break;
			}
		}
	}
	
	cout << cnt;
	return 0;
}