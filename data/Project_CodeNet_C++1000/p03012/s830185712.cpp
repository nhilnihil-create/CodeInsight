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
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		sum += n;
		v[i] = n;
	}

	int s = 0;
	int ret = -1;
	int d = INF;

	for (int i = 0; i < N; i++) {
		s += v[i];
		int t = sum - s;
		if (d > abs(s - t)) {
			d = abs(s - t);
		}
	}

	cout << d << endl;
}