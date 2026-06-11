#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char c;
	cin >> c;
	if ('A' <= c && c <= 'Z') {
		cout << 'A' << endl;
	}
	else {
		cout << 'a' << endl;
	}
	return 0;
}