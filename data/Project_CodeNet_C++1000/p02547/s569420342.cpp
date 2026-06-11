//in the name of GOD//
#include <bits/stdc++.h>

using namespace std;

int n, g, x, y;
bool b = false;

int main()
{
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		cin >> x>> y;
		if(x == y)
		{
			g++;
		}
		else
		{
			g = 0;
		}
		if(g == 3)
		{
			b = true;
		}	
	}
	
	b == true? cout << "Yes":cout << "No";
	
	
	return 0;
}