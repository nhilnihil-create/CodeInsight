#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string str;
	string item;
	vector<string> list;
	getline(cin, str);
	stringstream ss(str);
	while (getline(ss, item, ' ') && !item.empty()) {
		list.push_back(item);
	}

	int a = list[0].c_str()[0];
	int b = list[1].c_str()[0];
	int c = list[2].c_str()[0];

	if (a < b)
	{
		if (b < c)
		{

			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}