#include <bits/stdc++.h>
#define ll long long
#define M 1000000007 
#define MM 998244353
using namespace std;
 
int main()
{
	int n, flag = 0; 

	cin >> n; 

	for (int i = 1; i < 10; i++)
	{
		if (n%i == 0)
		{
			if (n/i<10)
			{
				cout << "Yes";
				flag = 1;
				exit(0);
			}
		}
	}

	if (flag == 0)
	{
		cout << "No";
	}

  	return 0;
}