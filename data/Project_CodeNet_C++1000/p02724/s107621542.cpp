#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll x; cin >> x;
	ll tmp = x;
	ll quo500 = tmp / 500;
	tmp -= 500 * quo500;
	ll quo5 = tmp / 5;
	cout << 1000 * quo500 + 5 * quo5 << endl;
	return 0;
}