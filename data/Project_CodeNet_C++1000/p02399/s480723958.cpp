#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int d = a / b;
	int r = a % b;
	double f = a / static_cast<double>(b);

	cout << d << " " << r << " " << fixed << setprecision(8) << f << "\n";
}