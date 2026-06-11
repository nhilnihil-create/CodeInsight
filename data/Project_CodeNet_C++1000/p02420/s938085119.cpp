#include <iostream>
#include <stdio.h>
#include <string.h>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main (void)
{
	int h[100],m,n;

	string a,left,right;

	for (int A = 0; A < 50; A++)
	{
		cin >> a;


		if (a == "-")
				{
					break;
				}

		cin >> m;

		for (int B = 0; B < m; B++)
		{
			cin >> h[B];

			n = 0;
							n = a.size();

			left = a.substr(0,h[B]);
			right = a.substr(h[B],n);

			a = right + left;

		}
		cout << a << endl;
	}

}