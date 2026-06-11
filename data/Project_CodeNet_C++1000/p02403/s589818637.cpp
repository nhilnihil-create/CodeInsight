#include <iostream>
using namespace std;

int main ()
{
	int x, y;
	while ((cin >> x >> y), x, y)
	{
		for (int i=1; i<=x; i++)
		{
		
			for (int j=1; j<=y; j++)
			{
				cout << "#";
				if (j==y) cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}