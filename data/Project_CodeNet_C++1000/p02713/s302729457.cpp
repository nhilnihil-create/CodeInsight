#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int k, total=0;;
	cin >> k;
	for(int i=1; i<=k; i++)
	{
		for(int j=1; j<=k; j++)
		{
			for(int n=1; n<=k; n++)
			{
				total += __gcd(__gcd(i, j), n);
			}
		}
	}
	cout << total;
}

