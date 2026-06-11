#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int cnt = 0;
	for (int i = 2; i < n; i++) {
		int a, b, c;
		a = v[i - 2];
		b = v[i - 1];
		c = v[i];
		if ((a < b) && (b < c)) cnt++;
		else if ((a > b) && (b > c)) cnt++;
	}

	cout << cnt << endl;
}