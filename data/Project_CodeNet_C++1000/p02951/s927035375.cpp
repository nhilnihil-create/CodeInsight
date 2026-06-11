#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int A, B, C; cin >> A >> B >> C;
	cout << max(C - (A - B), 0);
}