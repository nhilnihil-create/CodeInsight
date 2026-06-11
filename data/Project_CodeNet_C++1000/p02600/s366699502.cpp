#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int X;
	cin >> X;

	int ans = 8 - (X - 400) / 200;

	cout << ans << "\n";

	return 0;
}
