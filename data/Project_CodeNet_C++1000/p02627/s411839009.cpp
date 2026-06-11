#include <iostream>

using namespace std;

int main()
{
	char a;
	cin >> a;

	if (a <= 'Z' && 'A' <= a)
	{
		cout << "A" << endl;
	}
	else
	{
		cout << "a" << endl;
	}

	return 0;
}