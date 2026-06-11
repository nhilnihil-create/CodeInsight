#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;
const long long MOD = 1000000000 + 7;

int main() {
	string S; cin >> S;
	rep(i, S.size() - 1) {
		if (S[i] == S[i + 1]) {
			cout << "Bad";
			return 0;
		}
	}
	cout << "Good";
}