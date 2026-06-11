#include <iostream>
#include <iomanip>
using namespace std;

const int mxN = 2e5 + 5;
long long a[mxN], cnt[mxN];

int main() {
	double l;
	cin >> l;
	cout << fixed << setprecision(7) << l * l * l / 27;
}
