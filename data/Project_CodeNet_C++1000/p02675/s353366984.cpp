#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	string N;
	cin >> N;

	switch (*N.rbegin())
	{
	case '3':
		cout << "bon\n";
		break;
	case '0':
	case '1':
	case '6':
	case '8':
		cout << "pon\n";
		break;
	default:
		cout << "hon\n";
		break;
	}
	return;
}

int main() {

//	while (1)
		func();
	return 0;
}
