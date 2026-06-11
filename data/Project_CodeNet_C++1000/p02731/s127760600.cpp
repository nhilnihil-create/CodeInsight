#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
	double L;
	cin >> L;

	double edge = L / 3;
	double ans = edge * edge * edge;



	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
