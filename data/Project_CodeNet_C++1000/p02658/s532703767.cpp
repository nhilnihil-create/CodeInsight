#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a, over=0;
	long long int total=1;
	cin >> a;
	for(int k=0; k<a; k++)
	{
		long long int b;
		cin >> b;
		if(b != 0 && total > 1000000000000000000ll/b)
		{
			over++;
		}
		else if(b == 0)
		{
			cout << 0;
			return 0;
		}
		else
		{
			total *= b;
		}	
	}
	if(over > 0)
	{
		cout << -1;
	}
	else
	{
		cout << total;	
	}
}

