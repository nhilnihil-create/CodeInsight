#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	string S;
	cin >> N >> S;

	bool f = 0;
	if (N % 2 == 0) {
		string a, b;
		a = S.substr(0, N / 2);
		b = S.substr(N / 2);
		//cout << a << ' ' << b << endl;
		if (a == b) f = 1;
	}

	cout << (f ? "Yes" : "No") << endl;
}