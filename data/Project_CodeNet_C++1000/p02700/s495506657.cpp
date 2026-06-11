#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while(a>0 || c>0)
	{
		c -= b;
		if(c<=0)
		{
			cout << "Yes";
			return 0;
		}
		a -= d;
		if(a <= 0)
		{
			cout << "No";
			return 0;
		}
	}
}

