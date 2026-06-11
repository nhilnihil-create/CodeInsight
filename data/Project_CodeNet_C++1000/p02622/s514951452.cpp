#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#define ll long long int
using namespace std;
int h[6], w[6];

int main() {
	ll len, ans = 0;
	string S, T;

	cin >> S >> T;

	len = (ll)(S.length());

	for (int i = 0; i < len; i++){
		if (S[i] == T[i])
			continue;
		ans++;
	}

	cout << ans << endl;

	return 0;
}