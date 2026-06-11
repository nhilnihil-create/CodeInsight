#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<double> x(N), y(N);
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

	vector<int> P(N);
	for (int i = 0; i < N; i++) P[i] = i;

	double sum = 0;
	int c = 0;

	do {
		c++;
		double s = 0;
		for (int i = 1; i < N; i++) {
			double a, b, n;
			a = abs(x[P[i]] - x[P[i - 1]]);
			b = abs(y[P[i]] - y[P[i - 1]]);
			a *= a;
			b *= b;
			n = sqrt(a + b);
			s += n;
		}
		sum += s;
	} while (next_permutation(P.begin(), P.end()));

	cout << fixed << setprecision(10);
	cout << sum / c << endl;
}