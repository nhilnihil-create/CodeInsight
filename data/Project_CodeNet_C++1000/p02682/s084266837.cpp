#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d,count=0,x=0;
	cin >> a >> b >> c >> d;
	if (a > d)
	{
		cout << d;
	}
	else if ((a + b) >= d)
	{
		cout << a;
	}
	else
	{
		cout << a - (d - (a + b));
	}
	



}

	
	

