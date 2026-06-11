#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int n, m, t=0;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			t ++;	
		}	
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=i+1; j<=m; j++)
		{
			t ++;	
		}	
	}
	cout << t;
	
}

