#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, D;
	cin >> N >> D;

	int d = D * 2 + 1;
	int ret = N / d;
	if (N % d) ret++;

	cout << ret << endl;
}