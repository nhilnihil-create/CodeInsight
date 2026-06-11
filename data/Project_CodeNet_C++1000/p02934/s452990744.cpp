#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	double res = 0;
	for(int i = 1; i <= n; ++i) {
		double x;
		cin >> x;
		res += 1 / x;
	}
	cout << fixed << setprecision(10) << 1 / res;
}
