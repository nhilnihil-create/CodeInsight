/**
 *	author:		Yoseph Weissman
 *	created:	17.06.2020 09:53:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int sum = a1+a2+a3;
	if (sum >= 22)
		cout << "bust\n";
	else
		cout << "win\n";
	return 0;
}
