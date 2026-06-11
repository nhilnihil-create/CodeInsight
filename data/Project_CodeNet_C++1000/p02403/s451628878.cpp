#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
	int nW, nH;
	while (cin >> nW >> nH)
	{
		if (0 == nW && 0 == nH)
		{
			break;
		}
		for (int i = 0; i < nW; ++i)
		{
			for (int j = 0; j < nH; j++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;

	}

	//system("pause");
	return 0;
}