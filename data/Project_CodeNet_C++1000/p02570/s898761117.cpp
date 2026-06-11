/**
 *    author:  yoseph
 *    created: 08.09.2020 23:31:00      
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d,t,s;
	cin >> d >> t >> s;
	int cost = d / s + (d % s == 0 ? 0 : 1);
	cout << (cost <= t ? "Yes" : "No");
	return 0;
}
