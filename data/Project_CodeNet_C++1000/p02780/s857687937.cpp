#include <iostream>
#include <iomanip>
using namespace std;

const int mxN = 2e5 + 5;
double prefix[mxN];

int main() {
	int n, k;
	cin >> n >> k;
	double answer = -1;
	for(int i = 1; i <= n; ++i) {
		double x;
		cin >> x;
		x = (1 + x) / 2;
		prefix[i] = prefix[i - 1] + x;
		if(i >= k)
			answer = max(answer, prefix[i] - prefix[i - k]);
	}
	cout << fixed << setprecision(7) << answer;
}
