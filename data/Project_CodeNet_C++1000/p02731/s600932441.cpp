#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int l;
	cin >> l;
	double ans, side;

	side = l / 3.0;
	ans = side*side*side;

	cout << fixed << setprecision(12) << ans;
	return 0;
}