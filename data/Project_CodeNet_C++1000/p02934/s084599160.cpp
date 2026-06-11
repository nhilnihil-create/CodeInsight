#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	double A;

	double ans = 0.0;
	for (int i = 0; i < N; ++i) {
		cin >> A;
		ans += (1.0 / A);
	}

	ans = 1.0 / ans;

	cout << fixed << setprecision(14) << ans << endl;
	return 0;
}

