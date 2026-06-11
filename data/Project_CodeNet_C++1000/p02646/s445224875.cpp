#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int main() {

	FAST;

	int a, v;
	int b, w;
	int t;
	cin >> a >> v >> b >> w >> t;
	if (v <= w) {
		cout << "NO\n";
	}
	else {
		int k = (abs(b - a) + (v - w - 1)) / (v - w);
		cout << ((k <= t) ? "YES\n" : "NO\n");
	}
	return 0;
}