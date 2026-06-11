#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int a, b; cin >> a >> b;

	if ((2 * b) >= a) {
		cout << 0;
		return 0;
	} else {
		cout << (a - (b * 2));
	}



	return 0;

}