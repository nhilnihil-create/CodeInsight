#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int mxN = 55;
double a[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	double res = (a[1] + a[2]) / 2;
	for(int i = 3; i <= n; ++i)
		res = (res + a[i]) / 2;
	cout << setprecision(10) << fixed << res;
}
