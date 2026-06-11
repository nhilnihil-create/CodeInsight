#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t sub(int64_t n) {
	int64_t a = (n + 1) * n / 2;
	return a;
}

int main() {
	int64_t N;
	cin >> N;

	map<string, int64_t> m;

	for (int64_t i = 0; i < N; i++) {
		string S;
		cin >> S;
		sort(S.begin(), S.end());
		if (m.count(S) == 0) {
			m[S] = 1;
		}
		else {
			m.at(S)++;
		}
	}

	int64_t ret = 0;
	for (auto a: m) {
		int64_t n = a.second;
		//cout << n << endl;
		if (n == 1) continue;
		ret += sub(n - 1);
		//cout << ret << endl;
	}

	cout << ret << endl;
}