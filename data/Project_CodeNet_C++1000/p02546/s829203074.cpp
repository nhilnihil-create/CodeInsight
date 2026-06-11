/*
                ******
		
        Author: Nguyen Phuc Chuong

                ******
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	if (s.back() == 's') {
		s += "es";
	} else {
		s += 's';
	}
	cout << s;
	return 0;
}
