#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, s;
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		if (i == 0)cout << s;
		else cout << " " << s;
	}
	for (int i = 0; i < n - k; i++) {
		if (s == 1000000000)cout << " " << 99999999;
		else cout << " " << 1000000000;
	}
}