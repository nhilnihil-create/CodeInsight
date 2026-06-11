#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	bool b = true;
	for (int i = 0; i < S.size(); i++) {
		if (i & 1) {
			if (S[i] == 'R') b = 0;
		}
		else {
			if (S[i] == 'L') b = 0;
		}
	}

	cout << (b ? "Yes" : "No") << endl;
}