#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	cout << (ll) pow(2, floor(log2(n))+1)-1;

	return 0;
}