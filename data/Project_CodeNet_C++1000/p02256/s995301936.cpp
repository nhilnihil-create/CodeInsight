#include <iostream>
using namespace std;

bool IsXBig(int x, int y)
{
	if(x >= y)
		return true;
	else 
		return false;
}

int main()
{
	int x,y;
	int gcd;
	cin >> x;
	cin >> y;

	/* ??°????°??´???? */
	while(true)
	{
		if(x % y == 0){gcd = y;break;}
		else if (y % x == 0){gcd = x;break;}

		if(IsXBig(x,y))
		{
		/* x >= y */
			x = x % y;
		} else 
		{
		/* x < y */
			y = y % x;
		}
	}

	cout << gcd << endl;

	return 0;
}