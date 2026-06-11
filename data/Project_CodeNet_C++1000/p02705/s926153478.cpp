#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = acos(-1);

int main() {
	int r;
	cin >> r;
	double ans = (double)2 * PI * r;
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}