#define _USE_MATH_DEFINES

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


	double n, s[1001], a, sum, m,SUM;


	while (1){
		cin >> n;

		sum = 0;

		SUM = 0;

		if (n == 0)break;

		for (int i = 0; i < n; i++)
		{
			cin >> s[i];

			sum += s[i];
		}

		m = sum / n;

		for (int i = 0; i < n; i++)
		{
			SUM += pow(s[i] - m, 2);
		}

		SUM = SUM / n;

		printf("%lf\n",sqrt(SUM));
	}

	return 0;
}