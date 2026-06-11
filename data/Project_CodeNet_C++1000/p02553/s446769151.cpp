#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long int total=-1e18, a, b, c, d;
	cin >> a >> b >> c >> d;
	if(total < a*c)
	{
		total = a*c;
	}
	if(total < a*d) 
	{
		total = a*d;
	}
	if(total < b*c)
	{
		total = b*c;
	}
	if(total <b*d)
	{
		total = b*d;
	}
	cout << total;
}

