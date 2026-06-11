#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, X;
	cin >> N >> X;

	vector<int> v(N);
	int c = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (!i) v[i] = n;
		else v[i] = v[i - 1] + n;
		if (v[i] <= X) c++;
	}

	cout << ++c << endl;
}