#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s;
	if(s[(int)(s.size()) - 1] == 's')
		s += "es";
	else
		s += "s";
	return cout << s << endl, 0;
}