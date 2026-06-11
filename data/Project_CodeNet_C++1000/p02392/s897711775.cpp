#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//#include <map>
//#include <algorithm>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	vector<string> vStr;

	while (str.find(' ') != -1)
	{
		vStr.push_back(str.substr(0, str.find(' ')));
		str.erase(0, str.find(' ') + 1);
	}
	vStr.push_back(str);

	int a, b, c;
	a = stoi(vStr.at(0));
	b = stoi(vStr.at(1));
	c = stoi(vStr.at(2));

	if (a < b && b < c)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;

	}
	return 0;
}