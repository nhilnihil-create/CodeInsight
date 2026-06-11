/**
 *    author:  yoseph
 *    created: 27.07.2020 11:27:18      
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin >> x;
	if (x >= 400 && x <=599)
		cout << 8 << "\n";
	else if (x >= 600 && x <= 799)
		cout << 7 << "\n";
	else if (x >= 800 && x <= 999)
		cout << 6 << "\n";
	else if (x >= 1000 && x <= 1199)
		cout << 5 << "\n";
	else if (x >= 1200 && x <= 1399)
		cout << 4 << "\n";
	else if (x >= 1400 && x <= 1599)
		cout << 3 << "\n";
	else if (x >= 1600 && x <= 1799)
		cout << 2 << "\n";
	else if (x >= 1800 && x <= 1999)
		cout << 1 << "\n";
	return 0;
}
