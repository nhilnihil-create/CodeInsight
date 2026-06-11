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

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int n = i;
		int cnt = 0;
		while (n) {
			cnt++;
			n /= 10;
		}
		if (cnt & 1) ret++;
	}

	cout << ret << endl;
}