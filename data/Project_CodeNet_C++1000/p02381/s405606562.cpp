#include <iostream>
#include <stdio.h>
#include <string.h>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <valarray>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main (void)
{
	long double s[1000],Hei,kari;

	long int n;

for (long int A = 0; A < 1000; A++)
{
		cin >> n;

		if (n == 0)
		{
			break;
		}


	for (long int i = 0; i < n; i++)
	{
		cin >> s[i];
		Hei += s[i];

	}

	for (long int i = 0; i < n; i++)
	{
		kari += (s[i] - Hei / n) * (s[i] - Hei / n);
	}


	cout << fixed << setprecision(8) << sqrt(kari / n) << endl;

	Hei = 0;
	kari = 0;

}
}