#include<iostream>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int x = 0;
	for (char c : s) {
		x += (int)(c - '0');
	}

	if (x % 9 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}