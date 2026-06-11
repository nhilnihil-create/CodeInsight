#include "iostream"
#include "cmath"
#include "iomanip"
using namespace std;

int main(int argc, char const *argv[])
{
	double x1, y1, x2, y2=0;

	cin >> x1 >> y1 >> x2 >> y2;

	// printf("%.10f\n", sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) ));
	cout << setprecision(10) << sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) ) <<endl;
	return 0;
}
