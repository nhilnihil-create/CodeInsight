#include <iostream>

using namespace std;

void solve()
{
	int x, y;
	while (cin >> x >> y, x || y)
	{
		if (x < y)
		{
			cout << x << " " << y << endl;
		}
		else
		{
			cout << y << " " << x << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}