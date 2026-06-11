#include <bits/stdc++.h>

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const unsigned int M = 1e9 + 7;

int32_t main() {
	fastio;

	string a[3] = {"Sunny", "Cloudy", "Rainy"};
	string s;
	cin >> s;
	for(int i = 0; i < 3; ++i) {
		if(a[i] == s) {
			cout << a[(i + 1) % 3];
			break;
		}
	}

	return 0;
}
