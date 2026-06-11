#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double L;

	cin >> L;

	double x = L / 3;

	cout << fixed << setprecision(20) << x * x * x << endl;
}