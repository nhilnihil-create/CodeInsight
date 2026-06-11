#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int cun = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == t[i])
			cun++;
	}
	if (cun == n && n + 1 == t.length())
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}