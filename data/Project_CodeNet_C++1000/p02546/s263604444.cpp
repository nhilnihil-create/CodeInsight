#include <iostream>
using namespace std;

int main()
{
	string s1;
	int len;
	cin >> s1;

	len = s1.size();

	if (s1[len-1] == 's')
	{
		s1.insert(len, "es");
	}
	else
	{
		s1.insert(len, "s");
	}

	cout << s1 << endl;
}