#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	cout << a / b << endl;
	cout << a % b << endl;
	double c, d; c = a; d = b;
	cout << fixed << setprecision(6) << c / d << endl;
	return 0;
}
