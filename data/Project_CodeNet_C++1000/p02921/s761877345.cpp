#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0;
	string A, B;
	cin >> A >> B;
	if (A.at(0) == B.at(0)) {
		a++;
	}
	if (A.at(1) == B.at(1)) {
		a++;
	}
	if (A.at(2) == B.at(2)) {
		a++;
	}
	cout << a << endl;
}
