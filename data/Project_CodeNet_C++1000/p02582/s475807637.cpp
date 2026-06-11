// questionA.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>

using namespace std;
std::map<string, int> dictionary{
	{"RRR", 3},
	{"SSS", 0},
	{"RRS", 2},
	{"SRR", 2},
	{"SSR", 1},
	{"RSR", 1},
	{"RSS", 1},
	{"SRS", 1}
};

int main()
{
	//cout << "Hello cmake!" << endl;
	string s;
	cin >> s;
	cout << dictionary[s];
	return 0;
}