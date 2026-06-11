#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int K, X;
	cin >> K >> X;

	int L = X - (K - 1);
	int R = X + (K - 1);

	for (int i = L; i <= R; i++) {
		if (i!=L) cout << ' ';
		cout << i;
	}
	cout << endl;
}