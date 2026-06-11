#include <iostream>
#include <cmath>

int Compare_Func(const int &arg_a, const int &arg_b , int a);
int Total_Func(int &arg_a, int &arg_b);

const int MIN   = 1;
const int MAX   = 10;
const int ERROR = -1;

int main()
{
	int a = 0;
	int Total = 0;
	int Result = 0;
	
	std::cin >> a;

	Result = Compare_Func(MIN, MAX, a);
	if (ERROR != Result)
	{
		Total = Total_Func(Total, a);
		std::cout << Total << std::endl;
	}
	return 0;
}

int Compare_Func(const int &arg_a, const int &arg_b, int a)
{
	if ((arg_a > a) || (arg_b < a))
	{
		return ERROR;
	}
	return 0;
}

int Total_Func(int &arg_a, int &arg_b)
{
	arg_a = arg_b + ((int)std::pow(arg_b, 2.0)) + ((int)std::pow(arg_b, 3.0));
	return arg_a;
}