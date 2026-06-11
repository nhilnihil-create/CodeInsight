#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double stan_dev(double [], int);

double stan_dev(double s[], int count)
{
	double a = 0;
	double average = 0;
	for (int i = 0; i < count; ++i)
	{
		average += s[i];
	}
	average /= count;
	for (int i = 0; i < count; ++i)
	{
		a += pow(s[i] - average, 2.0); 
	}
	return sqrt(a / count);
}

int main(int argc, char const *argv[])
{
	int count = 0;
	while(true)
	{
		cin >> count;
		if (count == 0) break;
		double s[count];

		for (int i = 0; i < count; ++i)
		{
			cin >> s[i];
		}
		double a = stan_dev(s, count);
		printf("%lf\n", a);
	}
		
	return 0;
}