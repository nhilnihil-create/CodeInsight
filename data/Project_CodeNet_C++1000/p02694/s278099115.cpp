#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll x;
	cin >> x;
	ll p = 100 , step = 0;
	while (p < x) {
		p += p / 100;
		step++;
	}
	cout << step << endl;
	return 0;
}