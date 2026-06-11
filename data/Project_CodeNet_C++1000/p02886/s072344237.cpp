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

	int64_t sum = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += (int64_t)v[i] * v[j];
		}
	}

	cout << sum << endl;
}