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
	string S, T;
	cin >> S >> T;

	if (S + T[T.length() - 1] == T) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
