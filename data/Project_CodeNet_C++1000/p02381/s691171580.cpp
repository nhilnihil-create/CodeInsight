#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double n;
	double sum;
	double ave;
	double hyojun;
	double s[1000];
	double a[1000];
	int count = 0;

	while (1)
	{
		sum = 0;
		hyojun = 0;

		cin >> n;
		
		if (n==0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			sum = sum + s[i];
		}

		ave = sum / n;

		for (int i = 0; i < n; i++)
		{
			hyojun = hyojun + (s[i] - ave)*(s[i] - ave);
		}

		a[count] = sqrt(hyojun / n);
		count++;

	}

	for (int i = 0; i < count; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}