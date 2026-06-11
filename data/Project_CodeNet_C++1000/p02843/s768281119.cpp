#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int X;
	cin >> X;

	int sur = X % 100;
	int div = X / 100;

	if (sur <= 5 * div) cout << 1 << endl;
	else cout << 0 << endl;
}