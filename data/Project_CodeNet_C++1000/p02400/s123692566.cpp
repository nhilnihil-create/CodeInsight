#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double r;
	cin >> r;

	const double PI = 3.14159265359;
	cout << fixed << setprecision(6) << r * r * PI << " " << r * 2 * PI << "\n";
}