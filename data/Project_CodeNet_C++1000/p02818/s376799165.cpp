#include <bits/stdc++.h>
using namespace std;



int main() {
	long long a, b, k;
	cin >> a >> b >> k;
	long long x = min(a, k);
	a -= x;
	k -= x;
	x = min(b, k);
	b -= x;

	cout << a << " " << b;
	return 0;
}