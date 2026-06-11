#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int R;
	cin >> R;
	double pi = acos(-1);
	double length = 2 * R * pi;
	cout << fixed << setprecision(2) << length << endl;
	return 0;
}