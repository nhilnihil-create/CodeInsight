#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double a;
	cin >> a;
	cout <<setprecision(6)<<fixed<< a*a* M_PI << " " << 2 * a*M_PI << endl;
	cin >> a;
	return 0;
}