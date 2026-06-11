//	-*- mode: C++ -*-
//	Distance II
//
//		Your task is to calculate the distance between two n dimensional vectors x={x1,x2,...,xn} and y={y1,y2,...,yn}.
//
//		The Minkowski's distance defined below is a metric which is a generalization of both the Manhattan distance and the Euclidean distance. 
//		Dxy=(∑i=1n|xi−yi|p)1p
//
//		It can be the Manhattan distance 
//		Dxy=|x1−y1|+|x2−y2|+...+|xn−yn|
//
//		where p=1. 
//
//		It can be the Euclidean distance 
//		Dxy=(|x1−y1|)2+(|x2−y2|)2+...+(|xn−yn|)2−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−√
//
//		where p=2. 
//
//		Also, it can be the Chebyshev distance 
//
//		Dxy=maxni=1(|xi−yi|)
//
//
//		where p=∞
//
//		Write a program which reads two n dimensional vectors x and y, and calculates Minkowski's distance where p=1,2,3,∞ respectively.
//
//	Input
//		In the first line, an integer n is given. In the second and third line, x={x1,x2,...xn} and y={y1,y2,...yn} are given respectively. The elements in x and y are given in integers.
//
//	Output
//		Print the distance where p=1,2,3 and ∞ in a line respectively. The output should not contain an absolute error greater than 10-5.
//
//	Constraints
//		1≤n≤100
//		0≤xi,yi≤1000
//	Sample Input
//		3
//		1 2 3
//		2 0 4
//	Sample Output
//		4.000000
//		2.449490
//		2.154435
//		2.000000

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

double ManhattanDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y);

double EuclideanDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y);

double ChebyshevDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y);

double MinkowskiDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y);

int	main(int	argc,
		 char*	argv[])
{
	int	n	{0};
	std::cin >> n;

	std::vector<int>	x	{};
	for(int i = 0; i < n; i++){
		int	xi	{0};
		std::cin >> xi;
		x.push_back(xi);
	}

	std::vector<int>	y	{};
	for(int i = 0; i < n; i++){
		int	yi	{0};
		std::cin >> yi;
		y.push_back(yi);
	}

	std::cout << std::fixed << std::setprecision(6) << ManhattanDistance(n, x, y) << '\n';
	std::cout << std::fixed << std::setprecision(6) << EuclideanDistance(n, x, y) << '\n';
	std::cout << std::fixed << std::setprecision(6) << MinkowskiDistance(n, x, y) << '\n';
	std::cout << std::fixed << std::setprecision(6) << ChebyshevDistance(n, x, y) << '\n';

    return 0;
}

double ManhattanDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y)
{
	double	d	{0};

	for(int i = 0; i < n; i++){
		d	+= abs(x[i] - y[i]);
	}

	return d;
}

double EuclideanDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y)
{
	unsigned long long	d	{0};

	for(int i = 0; i < n; i++){
		unsigned int	_d	= abs(x[i] - y[i]);
		d	+= (_d * _d);
	}
	return sqrt(d);
}

double ChebyshevDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y)
{
	int	d	{0};

	for(int i = 0; i < n; i++){
		d = std::max(d, abs(x[i] - y[i]));
	}

	return static_cast<double>(d);
}

double MinkowskiDistance(int&	n,
						 std::vector<int>&	x,
						 std::vector<int>&	y)

{
	unsigned long long	d	{0};

	for(int i = 0; i < n; i++){
		d	+= pow(abs(x[i] - y[i]), 3);
	}

	return cbrt(d);
}

