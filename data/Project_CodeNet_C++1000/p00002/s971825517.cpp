#include <math.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>


using namespace std;

int main(void)
{
	int a, b;

	while (cin >> a >> b, !cin.eof())
	{
		int sum = to_string(a+b).length();


		cout << sum << endl;
	}

	return 0;
}