#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	string s;
	cin >> s;

	if (s == "SUN") {
		cout << 7 << endl;
	}
	else if(s == "SAT"){
		cout << 1 << endl;
	}
	else if (s == "MON") {
		cout << 6 << endl;
	}
	else if (s == "TUE") {
		cout << 5 << endl;
	}
	else if (s == "WED") {
		cout << 4 << endl;
	}
	else if (s == "THU") {
		cout << 3 << endl;
	}
	else {
		cout << 2 << endl;
	}

	return 0;
}