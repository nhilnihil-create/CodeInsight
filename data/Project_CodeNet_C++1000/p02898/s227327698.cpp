#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	cin >> N >> K;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n >= K) cnt++;
	}

	cout << cnt << endl;
}