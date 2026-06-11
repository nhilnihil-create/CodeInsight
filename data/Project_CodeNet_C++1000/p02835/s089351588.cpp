#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int sum = a + b + c;

	if (sum >= 22) cout << "bust" << endl;
	else cout << "win" << endl;
}