#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int X; cin >> X;
	if (X < 600) cout << 8;
	else if (X < 800) cout << 7;
	else if (X < 1000) cout << 6;
	else if (X < 1200) cout << 5;
	else if (X < 1400) cout << 4;
	else if (X < 1600) cout << 3;
	else if (X < 1800) cout << 2;
	else if (X < 2000) cout << 1;
	return 0;
}