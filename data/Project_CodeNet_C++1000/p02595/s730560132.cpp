#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a, b, total=0;
	cin >> a >> b;
	for(int i=0; i<a; i++)
	{
		double x, y, j;
		cin >> x >> y;
		j = sqrt(x*x+y*y);
		if(j <= b)
		{
			total++;
		}
	}
	cout << total;
}

