#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 1;
	char c0 = s.at(0);
	char c1 = '0';
	bool c2 = false;
	for (size_t i = 1; i < s.length(); i++){
		if (c2==false && s.at(i) != c0) {
			ans++;
			c0 = s.at(i);
		}
		else if (c2 == false && s.at(i) == c0) {
			if (i == s.length() - 1)c1 = s.at(i);
			else {
				ans++;
				c0 = s.at(i);
				c2 = true;
			}
		}
		else if(c2 ==true&&c1=='0'){
			c1 = s.at(i);
		}
		else {
			ans++;
			c0 = s.at(i);
			c1 = '0';
			c2 = false;
		}
	}
	cout << ans << endl;
}
