#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int A, B, N;
	cin >> A >> B >> N;

	Int ans = (A * min(B - 1, N)) / B;
	cout << ans << endl;

	return 0;
}
