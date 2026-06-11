#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double L;

	cin >> L;

	cout << fixed << setprecision(15) << (L / 3) * (L / 3) * (L / 3) << endl;
}