#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	char x = 'R';

	if (s[0] == x && s[1] == x && s[2] == x)
		cout << 3 << endl;
	else if (s[0] == x && s[1] == x || s[1] == x && s[2] == x)
		cout << 2 << endl;
	else if (s[0] == x || s[1] == x || s[2] == x)
		cout << 1 << endl;
	else
		cout << 0 << endl;

}