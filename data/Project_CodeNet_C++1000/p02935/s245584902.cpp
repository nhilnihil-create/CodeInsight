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
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	double ret = (double)(v[0] + v[1]) / 2;
	for (int i = 2; i < N; i++) {
		ret = (double)(ret + v[i]) / 2;
	}

	cout << fixed << setprecision(10) << ret << endl;
}