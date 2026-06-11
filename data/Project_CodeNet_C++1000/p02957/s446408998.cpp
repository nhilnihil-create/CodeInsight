#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B;
	cin >> A >> B;

	if (abs(A - B) & 1) cout << "IMPOSSIBLE" << endl;
	else cout << (A + B) / 2 << endl;
}