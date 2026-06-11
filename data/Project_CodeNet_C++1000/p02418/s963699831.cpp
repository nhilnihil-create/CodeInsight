#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string s1, s2,moji;
	int i = -1;

	cin >> s1 >> s2;

	moji = s1 + s1;

	i = moji.find(s2);

	if (i != -1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;

}