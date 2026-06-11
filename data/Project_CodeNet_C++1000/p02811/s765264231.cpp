/**
 *	author:		Yoseph Weissman
 *	created:	01.07.2020 11:03:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,n;
	cin >> k >> n;
	if (k * 500 >= n) 
		cout << "Yes\n";
	else
		cout << "No\n";	
	return 0;
}
