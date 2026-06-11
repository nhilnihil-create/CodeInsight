#include <iostream>
#include <string>

using namespace std;

int main()
{
	string			line;
	string			line2;

	getline(cin, line);
	getline(cin, line2);

	line += line;

	string::size_type		pos = line.find(line2);
	if (pos != string::npos)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}