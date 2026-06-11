#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int a, b; cin >> a >> b;

	if (1 > a || a > 9) {
		cout << -1;
		return 0;
	} else if (1 > b || b > 9) {
		cout << -1;
		return 0;
	}

	cout << (a * b);

	return 0;

}