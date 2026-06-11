
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i,l;
	getline(cin, s);
	l = s.length();

	for (size_t i = 0; i < l; i++)
	{
		s.replace(i, 1, "x");
	}
	cout << s;

}

