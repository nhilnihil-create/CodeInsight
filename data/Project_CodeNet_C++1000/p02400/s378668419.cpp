#include <iostream>
#include <iomanip>
using namespace std;

# define PI 3.14159265358979323846

int main() {
	
	double r;
	cin >> r;

	cout << fixed << setprecision(6) << r * r * PI;
	cout << ' ';
	cout << fixed << setprecision(6) << 2 * r * PI;

	return 0;
}
