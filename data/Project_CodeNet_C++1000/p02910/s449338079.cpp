#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	string s; cin >> s;
	int count = 1;
	for (int i = 0; i < s.size(); i++) {

		if (count % 2 == 0) {
			if (s[i] == 'R') {
				cout << "No";
				return 0;
			}
		} else {
			if (s[i] == 'L') {
				cout << "No";
				return 0;
			}
		}
		count++;
	}
	cout << "Yes";
	return 0;

}