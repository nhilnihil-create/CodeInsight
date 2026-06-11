#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <cfloat>

using namespace std;

int d,integ;

int main()
{
	while(cin >> d, !cin.eof())
	{
		integ = 0;
		
		for( int i = 0 ; i+d <= 600; i += d)
		{
			integ += d*pow((float)(i), 2);
		}
		
		cout << integ << endl;
	}
	
	return 0;
}