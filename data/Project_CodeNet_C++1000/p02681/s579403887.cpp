#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string substrBack(string str, size_t pos, size_t len) {

	const size_t strLen = str.length();

	return str.substr(strLen - pos, len);
}

int main(void) {

	string s;
	string t;

	cin >> s >> t;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == t[i]) {

			continue;

		}
		else {

			cout << "No";
			return 0;

		}

	}

	cout << "Yes";
	
}