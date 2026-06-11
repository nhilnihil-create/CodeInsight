#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	s = '5' + s;
	bool ok1 = true, ok2 = true;
	for(int i = 1; i < (int)s.size(); ++i) {
		if(i % 2)
			ok1 &= s[i] != 'L';
		else
			ok2 &= s[i] != 'R';
	}
	cout << (ok1 & ok2 ? "Yes" : "No");
}
