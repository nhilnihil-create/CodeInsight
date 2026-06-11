#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <cstdio>





using namespace std;


int main()
{
	int count = 0, point = 0;

	while (true)
	{
		cin >> count;

		if (count == 0)
			break;

		double *s = new double[count];
		double sum = 0, ave = 0, _sum = 0, stddevi = 0;

		for (int i = 0; i < count; i++)
		{
			cin >> s[i];
			sum += s[i];
		}

		ave = sum / count;

		for (int i = 0; i < count; i++)
		{
			_sum += pow(s[i] - ave, 2.0);
		}

		stddevi = sqrt(_sum / count);

		cout << stddevi << endl;






	}
	
	

	
}