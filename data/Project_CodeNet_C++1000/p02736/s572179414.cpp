#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;

	string a;
	cin >> a;

	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		x[i] = a[i] - '0';
		x[i]--;
	}

	int xs = 0;
	for (int i = 0; i < N; i++) {
		int tmp = x[i] % 2;
		if (((N - 1) & i) != i)tmp *= 0;
		xs += tmp;
	}
	if (xs % 2 == 1) {
		cout << 1 << endl;
		return 0;
	}

	bool f = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] == 1)f = true;
	}
	if (f) {
		cout << 0 << endl;
		return 0;
	}

	
	int xs_ = 0;
	for (int i = 0; i < N; i++) {
		int tmp = x[i] / 2;
		if (((N - 1) & i) != i)tmp *= 0;
		xs_ += tmp;
	}
	if (xs_ % 2 == 1) {
		cout << 2 << endl;
	}
	else {
		cout << 0 << endl;
	}
}