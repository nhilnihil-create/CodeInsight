#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S,T;
	cin >> S >> T;
	int ans = 0;

	for (int i = 0; i < 3; i++) {
		if (S[i]==T[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
