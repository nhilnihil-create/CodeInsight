#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	cin >> N;

	double ret = 0.5;
	if (N & 1) ret = (double)(N / 2 + 1) / N;

	cout << fixed << setprecision(10) << ret << endl;
}