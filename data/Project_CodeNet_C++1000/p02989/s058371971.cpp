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

	int R = N / 2, L = R - 1;
	int ret = v[R] - v[L];

	cout << ret << endl;
}