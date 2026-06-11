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

	vector<int> v(N);
	double a = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		a += (double)1 / n;
	}

	double ans = 1 / a;

	cout << fixed << setprecision(10) << ans << endl;
}