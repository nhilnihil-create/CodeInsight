#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int toggle(char c)
{
	if (isupper(c)) {
		c = tolower(c);
	} else {
		c = toupper(c);
	}
	return c;
}

int main()
{
	string s;
	getline(cin, s);

	transform(s.begin(), s.end(), s.begin(), toggle);
	cout << s << endl;

	return 0;
}