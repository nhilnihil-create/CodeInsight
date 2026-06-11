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

	sort(S.begin(), S.end());
	bool b = false;
	if ((S[0] == S[1]) && (S[2] == S[3])) {
		if (S[1] != S[2]) b = true;
	}

	cout << (b ? "Yes" : "No") << endl;
}