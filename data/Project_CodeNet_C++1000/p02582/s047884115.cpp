// questionA.cpp : Defines the entry point for the application.
//

#include <iostream>

using namespace std;

int main()
{
	//cout << "Hello cmake!" << endl;
	string s;
	cin >> s;
	int ret_value = 1;
	if (s == "RRR")
		ret_value = 3;
	else if (s == "SSS")
		ret_value = 0;
	else if (s == "RRS" || s == "SRR")
		ret_value = 2;
	cout << ret_value;
	return 0;
}