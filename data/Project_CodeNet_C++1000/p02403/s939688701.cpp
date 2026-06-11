#include <iostream>
using namespace std;
int main()
{
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
		break;
		}
		for (int i = 1; i <= a; i++)
		{
			for (int i = 2; i <= b; i++)
			{
				cout << "#";
			}
		cout << "#" << endl;
		}cout << endl;
	}
}