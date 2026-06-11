#include<iostream>
#include<iomanip>
#include<cmath>
int main()
{
	double result[1000];
	int num;
	for(int i = 0;; i++)
	{
		int n;
		std::cin >> n;
		if(n == 0)
		{
			num = i;
			break;
		}
		double*val = new double[n];
		for(int j = 0; j < n; j++)
		{
			std::cin >> val[j];
		}
		double sum = 0;
		for(int j = 0; j < n; j++)
		{
			sum += val[j];
		}
		for(int j = 0; j < n; j++)
		{
			val[j] -= sum / n;
		}
		double sq_sum = 0;
		for(int j = 0; j < n; j++)
		{
			sq_sum += val[j] * val[j];
		}
		result[i] = sqrt(sq_sum / n);
	}
	for(int i = 0; i < num; i++)
	{
		std::cout << std::fixed << std::setprecision(10) << result[i] << std::endl;
	}
	return 0;
}
