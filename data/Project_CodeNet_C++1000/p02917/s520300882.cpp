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

	vector<int> B(N - 1);
	for (int i = 0; i < N - 1; i++) cin >> B[i];

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!i) ret += B[i];
		else if (i == N - 1) ret += B[i - 1];
		else ret += min(B[i - 1], B[i]);
	}

	cout << ret << endl;
}