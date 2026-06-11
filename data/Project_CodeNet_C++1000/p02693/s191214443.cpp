#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(c-c%a <= c && c-c%a >= b)
	{
		cout << "OK";
	}
	else
	{
		cout << "NG";
	}
}

