#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string ch; cin >> ch;
	if (ch[0] == 'A' && ch[1] == 'B' && ch[2] == 'C')
		cout << "ARC";
	else
		cout << "ABC" << endl;
	return 0;
}