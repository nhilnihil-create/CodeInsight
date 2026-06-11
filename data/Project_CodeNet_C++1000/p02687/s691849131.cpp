#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main()
{
	string a;
	cin >> a;

	if(a == "ABC") {
		cout << " ARC";
	}
	else if (a == "ARC") {
		cout << "ABC";
	}
}
