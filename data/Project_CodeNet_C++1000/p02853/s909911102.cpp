#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int X[2];
	cin >> X[0] >> X[1];
	int ans = 0;
	for(int i = 0; i < 2; i++) {
		if(X[i] == 3) ans += 100000;
		if(X[i] == 2) ans += 200000;
		if(X[i] == 1) ans += 300000;
	}
	if(X[0] == 1 && X[1] == 1) ans += 400000;
	cout << ans << "\n";
	return 0;
}