// ABC162A.cpp
//#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string ans = "No";
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '7') ans = "Yes";
	}
	cout << ans << endl;
}
