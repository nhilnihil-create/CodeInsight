#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int A, B; cin >> A >> B;
	if ((A + B) % 2 == 0)cout << (A + B) / 2;
	else if (A == B)cout << 0;
	else cout << "IMPOSSIBLE";
}