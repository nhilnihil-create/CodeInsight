#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int ret = C - (A - B);
	if (ret < 0) ret = 0;

	cout << ret << endl;
}