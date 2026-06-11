
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;

	double sum = 0;

	double x[101], y[101];

	double max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] ;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	for (double p = 1.000000; p <= 4.000000; p+=1.000000){
		if (p != 4){

			sum = 0;

			for (int i = 0; i < n; i++)
			{
				sum += pow(fabs(x[i] - y[i]), p);
			}

			printf("%lf\n",pow(sum,1.000000/p));

		}
		else
		{

			for (int i = 0; i < n; i++)
			{
				sum = fabs(x[i] - y[i]);

				if (sum > max)
				{
					max = sum;
				}
			}

			printf("%lf\n",max);

		}

	}
	

	return 0;
}