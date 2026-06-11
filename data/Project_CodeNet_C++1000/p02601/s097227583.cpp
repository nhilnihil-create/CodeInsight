#include<iostream>
using namespace std;

int main()
{
	int a, b, c, k, flag = 1;  // a is red, b is green, c is blue
	//blue > green > red 
	//c > b > a
	cin >> a >> b >> c >> k;
	while (a >= b)
	{
		k--;
		b *= 2;
		if (k < 0)
		{
			flag = 0;
			break;
		}
	}
	while (b >= c)
	{
		k--;
		c *= 2;
		if (k < 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}