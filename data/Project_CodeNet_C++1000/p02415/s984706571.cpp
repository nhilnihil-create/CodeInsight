#include <iostream>
#include <cctype>
#include <string>
using namespace std;


int main() {
	string input;
//	cin >> input;
	getline(cin, input);
	for (char& c : input) {
		if (c >= 'a' && c <= 'z') c = toupper(c);
		else if (c >= 'A' && c <= 'Z') c = tolower(c);
	}
	cout << input << endl;
	return 0;
}