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

	int a = (int)N / 1.08;
	int b = a + 1;
	int n, m;
	n = a * 1.08;
	m = b * 1.08;
	//cout << n << ' ' << m << endl;

	if (n == N) cout << a << endl;
	else if (m == N) cout << b << endl;
	else cout << ":(" << endl;
}