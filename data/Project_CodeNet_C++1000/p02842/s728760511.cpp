#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	for (double i = 1; i <= 50000; i += 1)
	{
		if((int)(i * 1.08) == n)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
 
	return 0;
}