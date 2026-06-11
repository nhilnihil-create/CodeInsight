#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	ll a, b, c; cin >> a >> b >> c;
	bool ans;
	if (c-a-b < 0) {
		ans = false;
	}
	else {
		ans = 4 * a * b < (a + b - c) * (a + b - c);
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}