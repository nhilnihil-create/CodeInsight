// questionA.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
	//cout << "Hello cmake!" << endl;
	int a;
	cin >> a;

	auto plus_one = [&a](int x)->int {return a*(1 + x); };
	cout << plus_one(plus_one(a)) << endl;

	return 0;
}