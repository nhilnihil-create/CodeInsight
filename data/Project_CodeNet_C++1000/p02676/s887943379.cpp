#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,found;
	cin >> n;
	string s;
	cin >> s;
	
	if(s.size() > n) {
		s = s.substr(0, n) + "...";
		cout << s << endl;
	} else {
		cout << s << endl;
	}

	
	return 0;
}