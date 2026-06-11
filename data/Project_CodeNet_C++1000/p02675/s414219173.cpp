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
	string N;
	cin >> N;
	char num = N[N.length()-1];

	if (num == '3') {
		cout << "bon" << endl;
	}
	else if (num == '0' || num == '1' || num == '6' || num == '8') {
		cout << "pon" << endl;
	}
	else {
		cout << "hon" << endl;
	}


}
