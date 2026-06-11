#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	char a;
	cin >> a;

	if ('a' <= a && a <= 'z') {
		cout << "a" << endl;
	}
	else {
		cout << "A" << endl;
	}
}
