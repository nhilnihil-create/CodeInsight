#define FOR(i, min, max) for(int (i) = (min); (i) < (max); (i)++)
#define MAX(a,b) ((a) > (b) ? (a) : (b)) 
#define SWAP(a,b) { int r = a; a = b; b = r; }

#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int stable(string c[], string z[], int n)
{
	bool order = true;
	FOR(i, 0, n - 1)
	{
		cout << c[i] << " ";
	}
	cout << c[n - 1] << endl;
	FOR(i, 1, n)
	{
		if (c[i][1] == c[i - 1][1])
		{
			bool ch = false;
			FOR(j, 0, n)
			{
				if (c[i] == z[j])
					ch = true;
				if (z[j] == c[i - 1])
				{
					if (ch)
						order = false;
					else
						break;
				}
			}
			if(!order)
				break;
		}
	}
	if (order)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	return 0;
}
int main()
{
	int n;
	string a[100], c[100], z[100];
	cin >> n;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		a[i] = s;
		c[i] = s;
		z[i] = s;
	}
	FOR(i, 0, n) //bubble
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j][1] < a[j - 1][1])
			{
				string str = a[j];
				a[j] = a[j - 1];
				a[j - 1] = str;
			}
		}
	}
	stable(a, z, n);
	FOR(i, 0, n) //select
	{
		int minj = i;
		FOR(j, i, n)
		{
			if (c[j][1] < c[minj][1])
				minj = j;
		}
		if (c[i][1] != c[minj][1])
		{
			string str = c[i];
			c[i] = c[minj];
			c[minj] = str;
		}
	}
	stable(c, z, n);
	return 0;
}