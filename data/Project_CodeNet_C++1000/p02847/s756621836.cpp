/**
 *	author:		Yoseph Weissman
 *	created:	08.07.2020 10:43:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s(1,'\0');
	cin >> s;
	if (s == "SUN") cout << 7 << "\n";
	else if (s == "SAT") cout << 1 << "\n";
	else if (s == "MON") cout << 6 << "\n";
	else if (s == "TUE") cout << 5 << "\n";
	else if (s == "WED") cout << 4 << "\n";
	else if (s == "THU") cout << 3 << "\n";
	else if (s == "FRI") cout << 2 << "\n";
	return 0;
}
