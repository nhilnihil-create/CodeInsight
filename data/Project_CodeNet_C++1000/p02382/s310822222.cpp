#include<iostream>
#include<iomanip>
#include<cmath>
int main()
{
	int n;
	std::cin >> n;
	int*x = new int[n], *y = new int[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> x[i];
	}
	for(int i = 0; i < n; i++)
	{
		std::cin >> y[i];
	}
	std::cout << std::fixed << std::setprecision(10);
	double manhattan = 0;
	for(int i = 0; i < n; i++)
	{
		manhattan += std::abs(x[i] - y[i]);
	}
	std::cout << manhattan << std::endl;
	double euclid_2 = 0;
	for(int i = 0; i < n; i++)
	{
		euclid_2 += (x[i] - y[i]) * (x[i] - y[i]);
	}
	std::cout << sqrt(euclid_2) << std::endl;
	double euclid_3 = 0;
	for(int i = 0; i < n; i++)
	{
		euclid_3 += std::abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
	}
	std::cout << cbrt(euclid_3) << std::endl;
	double chebychev = 0;
	for(int i = 0; i < n; i++)
	{
		if(chebychev < std::abs(x[i] - y[i]))
		{
			chebychev = std::abs(x[i] - y[i]);
		}
	}
	std::cout << chebychev << std::endl;
	return 0;
}
