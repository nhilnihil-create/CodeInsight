#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int main() {
	double a;
	cin >> a;
	cout << fixed << setprecision(10)<< a * a* M_PI << " " << a * 2 * M_PI << endl;
	return 0;
}
