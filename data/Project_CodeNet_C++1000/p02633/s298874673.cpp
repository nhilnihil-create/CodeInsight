#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	cout << x * 360 / __gcd(360, x) / x;

	return 0;
}